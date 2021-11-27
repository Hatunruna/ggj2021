#include "PlayerEntity.h"

#include <gf/AnimatedSprite.h>
#include <gf/RenderTarget.h>
#include <gf/Sprite.h>

#include <gf/Log.h>

#include "GameState.h"
#include "GameData.h"
#include "Constants.h"

namespace tlw {

  namespace {

    constexpr gf::Time MoveCooldown = gf::seconds(0.25f);

  }

  PlayerEntity::PlayerEntity(gf::ResourceManager& resources, GameState& state, const GameData& data)
  : m_state(state)
  , m_data(data)
  , m_moveCooldown(MoveCooldown)
  , m_currentDirection(gf::Direction::Right)
  , stillRuning(false)
  , m_waitUpTexture(resources.getTexture("images/raymond_up.png"))
  , m_runUpTexture(resources.getTexture("images/raymond_run_up.png"))
  , m_waitBottomTexture(resources.getTexture("images/raymond_bottom.png"))
  , m_runBottomTexture(resources.getTexture("images/raymond_run_bottom.png"))
  , m_waitLeftTexture(resources.getTexture("images/raymond_left.png"))
  , m_runLeftTexture(resources.getTexture("images/raymond_run_left.png"))
  , m_waitRightTexture(resources.getTexture("images/raymond_right.png"))
  , m_runRightTexture(resources.getTexture("images/raymond_run_right.png"))
  , m_currentAnimation(nullptr)
  {
    m_waitUpTexture.setSmooth(true);
    m_runUpTexture.setSmooth(true);
    m_runUpAnimation.addTileset(m_runUpTexture, gf::vec(9, 1), gf::seconds(1.0f / 25.0f), 9);

    m_waitBottomTexture.setSmooth(true);
    m_runBottomTexture.setSmooth(true);
    m_runBottomAnimation.addTileset(m_runBottomTexture, gf::vec(9, 1), gf::seconds(1.0f / 25.0f), 9);

    m_waitLeftTexture.setSmooth(true);
    m_runLeftTexture.setSmooth(true);
    m_runLeftAnimation.addTileset(m_runLeftTexture, gf::vec(6, 1), gf::seconds(1.0f / 25.0f), 6);

    m_waitRightTexture.setSmooth(true);
    m_runRightTexture.setSmooth(true);
    m_runRightAnimation.addTileset(m_runRightTexture, gf::vec(6, 1), gf::seconds(1.0f / 25.0f), 6);
  }

  void PlayerEntity::update(gf::Time time) {
    m_moveCooldown += time;

    if (m_state.hero.pos == m_state.hero.target) {
      m_state.hero.middle = m_state.hero.pos * TileSize;
      return;
    }

    if (m_moveCooldown > MoveCooldown) {
      m_state.hero.pos = m_state.hero.target;
      m_state.hero.middle = m_state.hero.pos * TileSize;
    } else {
      if (m_currentAnimation != nullptr) {
        m_currentAnimation->update(time);
      }
      m_state.hero.middle = gf::lerp(m_state.hero.pos * TileSize, m_state.hero.target * TileSize, m_moveCooldown.asSeconds() / MoveCooldown.asSeconds());
    }
  }

  void PlayerEntity::render(gf::RenderTarget &target, const gf::RenderStates &states) {
    gf::Sprite sprite;
    switch (m_currentDirection) {
    case gf::Direction::Up:
      sprite = m_waitUpTexture;
      m_currentAnimation = &m_runUpAnimation;
      break;
    case gf::Direction::Down:
      sprite = m_waitBottomTexture;
      m_currentAnimation = &m_runBottomAnimation;
      break;
    case gf::Direction::Left:
      sprite = m_waitLeftTexture;
      m_currentAnimation = &m_runLeftAnimation;
      break;
    case gf::Direction::Right:
      sprite = m_waitRightTexture;
      m_currentAnimation = &m_runRightAnimation;
      break;

    default:
      assert(false);
      break;
    }

    if (m_currentAnimation == nullptr || (m_state.hero.pos == m_state.hero.target && !stillRuning)) {
      sprite.setPosition(m_state.hero.middle);
      target.draw(sprite, states);
    } else {
      gf::AnimatedSprite animatedSprite;
      animatedSprite.setAnimation(*m_currentAnimation);
      animatedSprite.setPosition(m_state.hero.middle);
      target.draw(animatedSprite, states);
    }
  }

  void PlayerEntity::move(gf::Direction dir)
  {
    if (dir == gf::Direction::Center) {
      stillRuning = false;
      return;
    }
    stillRuning = true;

    if (m_moveCooldown < MoveCooldown) {
//       gf::Log::debug("Cooldown not yet finished!\n");
      return;
    }

    m_currentDirection = dir;

    gf::Vector2i nextPos = m_state.hero.pos + gf::displacement(dir);

    for (const auto& [characterType, character]: m_state.characters) {
      if (character.pos == nextPos && character.visibility == CharacterVisibility::Visible) {
//         gf::Log::debug("Collision with a character!\n");
        return;
      }
    }

    if (m_data.tiles(nextPos) != TileState::Walkable) {
//       gf::Log::debug("Collision with a tile!\n");
      return;
    }

//     gf::Log::debug("New target!\n");
    m_state.hero.target = nextPos;
    m_moveCooldown = gf::seconds(0);
  }
}
