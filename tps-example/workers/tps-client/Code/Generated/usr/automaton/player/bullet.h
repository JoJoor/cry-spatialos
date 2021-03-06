// Generated by SpatialOS codegen. DO NOT EDIT!
// source: automaton/player/bullet.schema
#ifndef SPATIALOS_SCHEMA_automaton_player_bullet_schema_9313139855193204537_INCLUDED
#define SPATIALOS_SCHEMA_automaton_player_bullet_schema_9313139855193204537_INCLUDED
#include <improbable/collections.h>
#include <improbable/worker.h>
#include <cstddef>
#include <cstdint>
#include <set>
#include <string>
#include <automaton/quaternion.h>

struct Pbio;
struct Pbio_Object;

namespace automaton {
namespace player {

// Forward declarations.
//----------------------------------------------------------------

class BulletData;

namespace detail {
IMPROBABLE_DLL_API const ::worker::detail::ClientComponentVtable& Vtable_Bullet();
struct IMPROBABLE_DLL_API GenericCommandObject_Bullet {
  std::uint32_t CommandId;
  ::worker::Variant<> CommandObject;
};
}  // ::detail

// Enumerations.
//----------------------------------------------------------------

// Data classes.
//----------------------------------------------------------------

class IMPROBABLE_DLL_API BulletData {
public:
  // Main constructor.
  BulletData(
      ::worker::EntityId creator,
      const ::automaton::Quaternion& rotation);
  // Creates a new instance with default values for each field.
  static BulletData Create();

  // Copyable and moveable.
  BulletData(BulletData&&) = default;
  BulletData(const BulletData&) = default;
  BulletData& operator=(BulletData&&) = default;
  BulletData& operator=(const BulletData&) = default;
  ~BulletData() = default;

  bool operator==(const BulletData&) const;
  bool operator!=(const BulletData&) const;

  // Field creator = 1.
  ::worker::EntityId creator() const;
  ::worker::EntityId& creator();
  BulletData& set_creator(::worker::EntityId);

  // Field rotation = 2.
  const ::automaton::Quaternion& rotation() const;
  ::automaton::Quaternion& rotation();
  BulletData& set_rotation(const ::automaton::Quaternion&);

private:
  ::worker::EntityId _creator;
  ::automaton::Quaternion _rotation;
};

// Component metaclasses and update classes.
//----------------------------------------------------------------

/**
 * This type can be supplied as the template parameter to all component-related templated types
 * and methods in the C++ worker API. For example:
 *
 *   using ::automaton::player::Bullet;
 *
 *   Bullet::Update update;
 *   connection.SendComponentUpdate< Bullet >(entity_id, update);
 *
 *   dispatcher.OnComponentUpdate< Bullet >(
 *       [&](const worker::ComponentUpdateOp< Bullet >& op) {
 *         worker::EntityId entity_id = op.GetEntityId();
 *         Bullet::Update update = op.GetUpdate();
 *       });
 *
 *   Bullet::Data data = entity.Get< Bullet >();
 */
struct IMPROBABLE_DLL_API Bullet : ::worker::detail::ComponentMetaclassBase<
    Bullet, ::automaton::player::detail::Vtable_Bullet> {
  static constexpr const ::worker::ComponentId ComponentId = 30003;
  using Data = ::automaton::player::BulletData;
  using GenericCommandObject = ::automaton::player::detail::GenericCommandObject_Bullet;

  class IMPROBABLE_DLL_API Update {
  public:
    // Default-constructible, copyable and movable.
    Update() = default;
    Update(Update&&) = default;
    Update(const Update&) = default;
    Update& operator=(Update&&) = default;
    Update& operator=(const Update&) = default;
    ~Update() = default;

    bool operator==(const Update&) const;
    bool operator!=(const Update&) const;

    /** Creates an Update from a ::automaton::player::BulletData object. */
    static Update FromInitialData(const ::automaton::player::BulletData& data);

    /**
     * Converts to a ::automaton::player::BulletData
     * object. It is an error to call this function unless *all* of the optional fields in this
     * update are filled in.
     */
    ::automaton::player::BulletData ToInitialData() const;

    /**
     * Replaces fields in the given ::automaton::player::BulletData
     * object with the corresponding fields in this update, where present.
     */
    void ApplyTo(::automaton::player::BulletData&) const;

    // Field creator = 1.
    const ::worker::Option< ::worker::EntityId >& creator() const;
    ::worker::Option< ::worker::EntityId >& creator();
    Update& set_creator(::worker::EntityId);

    // Field rotation = 2.
    const ::worker::Option< ::automaton::Quaternion >& rotation() const;
    ::worker::Option< ::automaton::Quaternion >& rotation();
    Update& set_rotation(const ::automaton::Quaternion&);

  private:
    ::worker::Option< ::worker::EntityId > _creator;
    ::worker::Option< ::automaton::Quaternion > _rotation;
  };

};

// Implementation details.
//----------------------------------------------------------------

namespace detail {

void Write_BulletData(const ::automaton::player::BulletData&, ::Pbio_Object*);

::automaton::player::BulletData Read_BulletData(::Pbio_Object*);

}  // ::detail
}  // ::player
}  // ::automaton

#endif  // SPATIALOS_SCHEMA_automaton_player_bullet_schema_9313139855193204537_INCLUDED
