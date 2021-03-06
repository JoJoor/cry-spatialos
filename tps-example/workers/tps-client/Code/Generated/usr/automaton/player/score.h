// Generated by SpatialOS codegen. DO NOT EDIT!
// source: automaton/player/score.schema
#ifndef SPATIALOS_SCHEMA_automaton_player_score_schema_14422881483244129229_INCLUDED
#define SPATIALOS_SCHEMA_automaton_player_score_schema_14422881483244129229_INCLUDED
#include <improbable/collections.h>
#include <improbable/worker.h>
#include <cstddef>
#include <cstdint>
#include <set>
#include <string>

struct Pbio;
struct Pbio_Object;

namespace automaton {
namespace player {

// Forward declarations.
//----------------------------------------------------------------

class ScoreData;

namespace detail {
IMPROBABLE_DLL_API const ::worker::detail::ClientComponentVtable& Vtable_Score();
struct IMPROBABLE_DLL_API GenericCommandObject_Score {
  std::uint32_t CommandId;
  ::worker::Variant<> CommandObject;
};
}  // ::detail

// Enumerations.
//----------------------------------------------------------------

// Data classes.
//----------------------------------------------------------------

class IMPROBABLE_DLL_API ScoreData {
public:
  // Main constructor.
  ScoreData(
      std::uint32_t kills,
      std::uint32_t deaths);
  // Creates a new instance with default values for each field.
  static ScoreData Create();

  // Copyable and moveable.
  ScoreData(ScoreData&&) = default;
  ScoreData(const ScoreData&) = default;
  ScoreData& operator=(ScoreData&&) = default;
  ScoreData& operator=(const ScoreData&) = default;
  ~ScoreData() = default;

  bool operator==(const ScoreData&) const;
  bool operator!=(const ScoreData&) const;

  // Field kills = 1.
  std::uint32_t kills() const;
  std::uint32_t& kills();
  ScoreData& set_kills(std::uint32_t);

  // Field deaths = 2.
  std::uint32_t deaths() const;
  std::uint32_t& deaths();
  ScoreData& set_deaths(std::uint32_t);

private:
  std::uint32_t _kills;
  std::uint32_t _deaths;
};

// Component metaclasses and update classes.
//----------------------------------------------------------------

/**
 * This type can be supplied as the template parameter to all component-related templated types
 * and methods in the C++ worker API. For example:
 *
 *   using ::automaton::player::Score;
 *
 *   Score::Update update;
 *   connection.SendComponentUpdate< Score >(entity_id, update);
 *
 *   dispatcher.OnComponentUpdate< Score >(
 *       [&](const worker::ComponentUpdateOp< Score >& op) {
 *         worker::EntityId entity_id = op.GetEntityId();
 *         Score::Update update = op.GetUpdate();
 *       });
 *
 *   Score::Data data = entity.Get< Score >();
 */
struct IMPROBABLE_DLL_API Score : ::worker::detail::ComponentMetaclassBase<
    Score, ::automaton::player::detail::Vtable_Score> {
  static constexpr const ::worker::ComponentId ComponentId = 30010;
  using Data = ::automaton::player::ScoreData;
  using GenericCommandObject = ::automaton::player::detail::GenericCommandObject_Score;

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

    /** Creates an Update from a ::automaton::player::ScoreData object. */
    static Update FromInitialData(const ::automaton::player::ScoreData& data);

    /**
     * Converts to a ::automaton::player::ScoreData
     * object. It is an error to call this function unless *all* of the optional fields in this
     * update are filled in.
     */
    ::automaton::player::ScoreData ToInitialData() const;

    /**
     * Replaces fields in the given ::automaton::player::ScoreData
     * object with the corresponding fields in this update, where present.
     */
    void ApplyTo(::automaton::player::ScoreData&) const;

    // Field kills = 1.
    const ::worker::Option< std::uint32_t >& kills() const;
    ::worker::Option< std::uint32_t >& kills();
    Update& set_kills(std::uint32_t);

    // Field deaths = 2.
    const ::worker::Option< std::uint32_t >& deaths() const;
    ::worker::Option< std::uint32_t >& deaths();
    Update& set_deaths(std::uint32_t);

  private:
    ::worker::Option< std::uint32_t > _kills;
    ::worker::Option< std::uint32_t > _deaths;
  };

};

// Implementation details.
//----------------------------------------------------------------

namespace detail {

void Write_ScoreData(const ::automaton::player::ScoreData&, ::Pbio_Object*);

::automaton::player::ScoreData Read_ScoreData(::Pbio_Object*);

}  // ::detail
}  // ::player
}  // ::automaton

#endif  // SPATIALOS_SCHEMA_automaton_player_score_schema_14422881483244129229_INCLUDED
