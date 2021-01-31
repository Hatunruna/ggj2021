#include "PlayerEntity.h"

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
  : m_playerTexture(resources.getTexture("images/raymond.png"))
  , m_state(state)
  , m_data(data)
  , m_moveCooldown(MoveCooldown)
  , m_RayUp(resources.getTexture("images/raymondUp.png"))
  , m_RayDown(resources.getTexture("images/raymondDown.png"))
  , m_RayLeft(resources.getTexture("images/raymondLeft.png"))
  , m_RayRight(resources.getTexture("images/raymondRight.png"))
  {
    m_playerTexture.setSmooth(true);
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
      m_state.hero.middle = gf::lerp(m_state.hero.pos * TileSize, m_state.hero.target * TileSize, m_moveCooldown.asSeconds() / MoveCooldown.asSeconds());
    }
  }

  void PlayerEntity::render(gf::RenderTarget &target, const gf::RenderStates &states) {
      gf::Sprite sprite;
      switch (m_currentDirection)
      {
      case gf::Direction::Up:
          sprite = m_RayUp;
          break;
      case gf::Direction::Down:
          sprite = m_RayDown;
          break;
      case gf::Direction::Left:
          sprite = m_RayLeft;
          break;
      case gf::Direction::Right:
          sprite = m_RayRight;
          break;

      default:
          sprite = m_RayLeft;
          break;
      }

    sprite.setPosition(m_state.hero.middle);
    target.draw(sprite, states);
  }

  void PlayerEntity::move(gf::Direction dir)
  {
    m_currentDirection = dir;

    if (m_moveCooldown < MoveCooldown) {
//       gf::Log::debug("Cooldown not yet finished!\n");
      return;
    }

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
