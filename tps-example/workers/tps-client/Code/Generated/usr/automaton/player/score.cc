// Generated by SpatialOS codegen. DO NOT EDIT!
// source: automaton/player/score.schema
#include <automaton/player/score.h>
#include <improbable/protobuf_interop.h>

namespace automaton {
namespace player {

// Implementation of ScoreData.
//----------------------------------------------------------------

ScoreData::ScoreData(
    std::uint32_t kills,
    std::uint32_t deaths)
: _kills{kills}
, _deaths{deaths} {}

ScoreData ScoreData::Create() {
  return {
      0,
      0};
}

bool ScoreData::operator==(const ScoreData& value) const {
  return
      _kills == value._kills &&
      _deaths == value._deaths;
}

bool ScoreData::operator!=(const ScoreData& value) const {
  return !operator==(value);
}

std::uint32_t ScoreData::kills() const {
  return _kills;
}

std::uint32_t& ScoreData::kills() {
  return _kills;
}

ScoreData& ScoreData::set_kills(std::uint32_t value) {
  _kills = value;
  return *this;
}

std::uint32_t ScoreData::deaths() const {
  return _deaths;
}

std::uint32_t& ScoreData::deaths() {
  return _deaths;
}

ScoreData& ScoreData::set_deaths(std::uint32_t value) {
  _deaths = value;
  return *this;
}

// Implementation of Score.
//----------------------------------------------------------------

constexpr const ::worker::ComponentId Score::ComponentId;

bool Score::Update::operator==(const Score::Update& value) const {
  return
      _kills == value._kills &&
      _deaths == value._deaths;
}

bool Score::Update::operator!=(const Score::Update& value) const {
  return !operator==(value);
}

Score::Update Score::Update::FromInitialData(const ::automaton::player::ScoreData& data) {
  Score::Update update;
  update._kills.emplace(data.kills());
  update._deaths.emplace(data.deaths());
  return update;
}

::automaton::player::ScoreData Score::Update::ToInitialData() const {
  return ::automaton::player::ScoreData(
      *_kills,
      *_deaths);
}

void Score::Update::ApplyTo(::automaton::player::ScoreData& data) const {
  if (_kills) {
    data.set_kills(*_kills);
  }
  if (_deaths) {
    data.set_deaths(*_deaths);
  }
}

const ::worker::Option< std::uint32_t >& Score::Update::kills() const {
  return _kills;
}

::worker::Option< std::uint32_t >& Score::Update::kills() {
  return _kills;
}

Score::Update& Score::Update::set_kills(std::uint32_t value) {
  _kills.emplace(value); return *this;
}

const ::worker::Option< std::uint32_t >& Score::Update::deaths() const {
  return _deaths;
}

::worker::Option< std::uint32_t >& Score::Update::deaths() {
  return _deaths;
}

Score::Update& Score::Update::set_deaths(std::uint32_t value) {
  _deaths.emplace(value); return *this;
}

// Serialization helpers.
//----------------------------------------------------------------

namespace detail {

void Write_ScoreData(
    const ::automaton::player::ScoreData& data, ::Pbio_Object* object) {
  ::Pbio_AddUint32(object, 1, data.kills());
  ::Pbio_AddUint32(object, 2, data.deaths());
}

::automaton::player::ScoreData Read_ScoreData(::Pbio_Object* object) {
  auto _kills = ::Pbio_GetUint32(object, 1);
  auto _deaths = ::Pbio_GetUint32(object, 2);
  return {
      std::move(_kills),
      std::move(_deaths)};
}

namespace {

void VtableBufferFree_Score(::worker::ComponentId, std::uint8_t* buffer) {
  delete[] buffer;
}

void VtableFree_Score(
    ::worker::ComponentId, std::uint8_t object_type,
    ::worker::detail::ClientObject* object) {
  if (object_type == ::worker::detail::ClientComponentVtable::Update) {
    delete static_cast< ::automaton::player::Score::Update* >(object);
  } else if (object_type == ::worker::detail::ClientComponentVtable::Snapshot) {
    delete static_cast< ::automaton::player::ScoreData* >(object);
  } else if (object_type == ::worker::detail::ClientComponentVtable::Request ||
             object_type == ::worker::detail::ClientComponentVtable::Response) {
    delete static_cast< GenericCommandObject_Score* >(object);
  }
}

::worker::detail::ClientObject* VtableCopy_Score(
    ::worker::ComponentId, std::uint8_t, ::worker::detail::ClientObject* object) {
  return object;
}

std::uint8_t VtableDeserialize_Score(
    ::worker::ComponentId, std::uint8_t object_type, const std::uint8_t* buffer,
    std::uint32_t length, ::worker::detail::ClientObject** object) {
  std::unique_ptr< ::Pbio, void (*)(::Pbio*)> pbio{
      ::Pbio_Create(), ::Pbio_Destroy};
  auto root = ::Pbio_GetRootObject(pbio.get());
  ::Pbio_MergeFromBuffer(root, buffer, length);
  if (object_type == ::worker::detail::ClientComponentVtable::Update) {
    *object = new ::automaton::player::Score::Update;
    auto client_object = static_cast< ::automaton::player::Score::Update* >(*object);
    {
      std::vector<std::uint32_t> fields_to_clear_vector;
      fields_to_clear_vector.insert(
          fields_to_clear_vector.end(),
          ::Pbio_GetUint32Count(root, /* fields to clear */ 1), 0);
      ::Pbio_GetUint32List(
         root, /* fields to clear */ 1, fields_to_clear_vector.data());
      std::set<std::uint32_t> fields_to_clear{fields_to_clear_vector.begin(),
                                              fields_to_clear_vector.end()};
      auto state_object = ::Pbio_GetObject(
          ::Pbio_GetObject(root, /* entity_state */ 2), 30010);
      if (::Pbio_GetUint32Count(state_object, 1)) {
        auto _kills = ::Pbio_GetUint32(state_object, 1);
        client_object->kills().emplace(std::move(_kills));
      }
      if (::Pbio_GetUint32Count(state_object, 2)) {
        auto _deaths = ::Pbio_GetUint32(state_object, 2);
        client_object->deaths().emplace(std::move(_deaths));
      }
    }
    {
    }
  } else if (object_type == ::worker::detail::ClientComponentVtable::Snapshot) {
    *object = new ::automaton::player::ScoreData{::automaton::player::detail::Read_ScoreData(::Pbio_GetObject(root, 30010))};
  } else if (object_type == ::worker::detail::ClientComponentVtable::Request) {
  } else if (object_type == ::worker::detail::ClientComponentVtable::Response) {
  }
  return ::Pbio_HasError(pbio.get()) == 0;
}

void VtableSerialize_Score(
    ::worker::ComponentId, std::uint8_t object_type,
    const ::worker::detail::ClientObject* object, std::uint8_t** buffer,
    std::uint32_t* length) {
  std::unique_ptr< ::Pbio, void (*)(::Pbio*)> pbio{
      ::Pbio_Create(), ::Pbio_Destroy};
  auto root = ::Pbio_GetRootObject(pbio.get());
  static_cast<void>(object);
  if (object_type == ::worker::detail::ClientComponentVtable::Update) {
    const auto& data = *static_cast< const ::automaton::player::Score::Update* >(object);
    {
      auto state_object = ::Pbio_AddObject(
          ::Pbio_AddObject(root, /* entity_state */ 2), 30010);
      if (data.kills()) {
        ::Pbio_AddUint32(state_object, 1, (*data.kills()));
      }
      if (data.deaths()) {
        ::Pbio_AddUint32(state_object, 2, (*data.deaths()));
      }
    }
    {
    }
  } else if (object_type == ::worker::detail::ClientComponentVtable::Snapshot) {
    ::automaton::player::detail::Write_ScoreData(
        *static_cast< const ::automaton::player::ScoreData* >(object),
        ::Pbio_AddObject(root, 30010));
  } else if (object_type == ::worker::detail::ClientComponentVtable::Request) {
    ::Pbio_AddObject(root, 30010);
  } else if (object_type == ::worker::detail::ClientComponentVtable::Response) {
    ::Pbio_AddObject(root, 30010);
  }
  *length = ::Pbio_GetWriteBufferLength(root);
  *buffer = new std::uint8_t[*length];
  ::Pbio_WriteToBuffer(root, *buffer);
}

}  // anonymous namespace

const ::worker::detail::ClientComponentVtable& Vtable_Score() {
  static const ::worker::detail::ClientComponentVtable vtable = {
      30010,
      &::automaton::player::detail::VtableBufferFree_Score,
      &::automaton::player::detail::VtableFree_Score,
      &::automaton::player::detail::VtableCopy_Score,
      &::automaton::player::detail::VtableDeserialize_Score,
      &::automaton::player::detail::VtableSerialize_Score,
  };
  return vtable;
}

}  // ::detail

}  // ::player
}  // ::automaton
