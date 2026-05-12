#define NIMPL { throw std::runtime_error("Not implemented"); }

#include "api.hpp"

using namespace Qounters;

void API::RegisterTemplate(std::string section, std::string title, Types::TemplateUIFn function) NIMPL;
void API::RegisterPremade(
    std::string mod, std::string name, Types::PremadeFn creation, Types::PremadeUIFn uiFunction, Types::PremadeUpdateFn update
) NIMPL;

void API::CloseTemplateModal() NIMPL;
void API::AddGroup(Options::Group group) NIMPL;

int API::GetActionId() NIMPL;
void API::SetSourceOptions(int actionId, UnparsedJSON options) NIMPL;
void API::SetColorOptions(int actionId, UnparsedJSON options) NIMPL;
void API::SetEnableOptions(int actionId, UnparsedJSON options) NIMPL;
void API::FinalizeAction() NIMPL;

BSML::ColorSetting* API::CreateColorPicker(
    UnityEngine::GameObject* parent,
    std::string name,
    UnityEngine::Color value,
    std::function<void(UnityEngine::Color)> onChange,
    std::function<void()> onClose
) NIMPL;

bool API::InSettings() {
    return false;
};
bool API::IsInstalled() {
    return false;
};
bool API::IsEnabled() {
    return false;
};
bool API::IsEnabledForSelection(GlobalNamespace::BeatmapKey beatmap) {
    return false;
};

#include "events.hpp"

void Events::RegisterToEvent(Types::Sources sourceType, std::string source, int event) NIMPL;
void Events::RegisterToEvent(Types::Sources sourceType, std::string source, std::string mod, int event) NIMPL;
void Events::RegisterToQountersEvent(Types::Sources sourceType, std::string source, int event) NIMPL;

void Events::BroadcastQountersEvent(int event) NIMPL;

#include "options.hpp"

std::vector<std::string_view> const Options::SaberStrings;
std::vector<std::string_view> const Options::DirectionStrings;
std::vector<std::string_view> const Options::AlignStrings;
std::vector<std::string_view> const Options::ShapeStrings;
std::vector<std::string_view> const Options::FillStrings;
std::vector<std::string_view> const Options::TypeStrings;
std::vector<std::string_view> const Options::AnchorStrings;
std::vector<std::string_view> const Options::SeparatorStrings;
std::vector<std::string_view> const Options::BaseGameObjectStrings;

Options::Preset Options::GetDefaultHUDPreset() NIMPL;

#include "pp.hpp"

bool PP::blSongValid = false;
MetaCore::PP::BLSongDiff PP::latestBeatleaderSong;
bool PP::ssSongValid = false;
MetaCore::PP::SSSongDiff PP::latestScoresaberSong;

bool PP::IsRankedBL() NIMPL;
bool PP::IsRankedSS() NIMPL;
float PP::CalculateBL(float percentage, GlobalNamespace::GameplayModifiers* modifiers, bool failed) NIMPL;
float PP::CalculateSS(float percentage, GlobalNamespace::GameplayModifiers* modifiers, bool failed) NIMPL;
void PP::GetMapInfo(GlobalNamespace::BeatmapKey map) NIMPL;
void PP::Reset() NIMPL;

#include "sources.hpp"

std::vector<std::pair<std::string, std::pair<Types::SourceFn<std::string>, Types::SourceUIFn>>> Sources::texts;
std::vector<std::pair<std::string, std::pair<Types::SourceFn<float>, Types::SourceUIFn>>> Sources::shapes;
std::vector<std::pair<std::string, std::pair<Types::SourceFn<UnityEngine::Color>, Types::SourceUIFn>>> Sources::colors;
std::vector<std::pair<std::string, std::pair<Types::SourceFn<bool>, Types::SourceUIFn>>> Sources::enables;

std::map<std::string, std::vector<Sources::PremadeInfo>> Sources::premades;
Sources::PremadeInfo* Sources::GetPremadeInfo(std::string const& mod, std::string const& name) NIMPL;

std::vector<std::string_view> const Sources::AverageCutPartStrings;
std::vector<std::string_view> const Sources::PBDisplayStrings;
std::vector<std::string_view> const Sources::NotesDisplayStrings;
std::vector<std::string_view> const Sources::PPLeaderboardStrings;
std::vector<std::string_view> const Sources::SaberSpeedModeStrings;
std::vector<std::string_view> const Sources::SpinometerModeStrings;
std::vector<std::string_view> const Sources::RankedStatusLeaderboardStrings;

std::string Sources::Text::GetStatic(UnparsedJSON options) NIMPL;
std::string Sources::Text::GetScore(UnparsedJSON options) NIMPL;
std::string Sources::Text::GetRank(UnparsedJSON options) NIMPL;
std::string Sources::Text::GetPersonalBest(UnparsedJSON options) NIMPL;
std::string Sources::Text::GetCombo(UnparsedJSON options) NIMPL;
std::string Sources::Text::GetMultiplier(UnparsedJSON options) NIMPL;
std::string Sources::Text::GetHealth(UnparsedJSON options) NIMPL;
std::string Sources::Text::GetTime(UnparsedJSON options) NIMPL;
std::string Sources::Text::GetAverageCut(UnparsedJSON options) NIMPL;
std::string Sources::Text::GetTimeDependence(UnparsedJSON options) NIMPL;
std::string Sources::Text::GetFails(UnparsedJSON options) NIMPL;
std::string Sources::Text::GetMistakes(UnparsedJSON options) NIMPL;
std::string Sources::Text::GetNotes(UnparsedJSON options) NIMPL;
std::string Sources::Text::GetPP(UnparsedJSON options) NIMPL;
std::string Sources::Text::GetSaberSpeed(UnparsedJSON options) NIMPL;
std::string Sources::Text::GetSpinometer(UnparsedJSON options) NIMPL;
std::string Sources::Text::GetFCPercent(UnparsedJSON options) NIMPL;

float Sources::Shape::GetStatic(UnparsedJSON options) NIMPL;
float Sources::Shape::GetScore(UnparsedJSON options) NIMPL;
float Sources::Shape::GetMultiplier(UnparsedJSON options) NIMPL;
float Sources::Shape::GetHealth(UnparsedJSON options) NIMPL;
float Sources::Shape::GetTime(UnparsedJSON options) NIMPL;
float Sources::Shape::GetAverageCut(UnparsedJSON options) NIMPL;
float Sources::Shape::GetNotes(UnparsedJSON options) NIMPL;

UnityEngine::Color Sources::Color::GetStatic(UnparsedJSON options) NIMPL;
UnityEngine::Color Sources::Color::GetPlayer(UnparsedJSON options) NIMPL;
UnityEngine::Color Sources::Color::GetRank(UnparsedJSON options) NIMPL;
UnityEngine::Color Sources::Color::GetPersonalBest(UnparsedJSON options) NIMPL;
UnityEngine::Color Sources::Color::GetCombo(UnparsedJSON options) NIMPL;
UnityEngine::Color Sources::Color::GetMultiplier(UnparsedJSON options) NIMPL;
UnityEngine::Color Sources::Color::GetHealth(UnparsedJSON options) NIMPL;

bool Sources::Enable::GetStatic(UnparsedJSON options) NIMPL;
bool Sources::Enable::GetRanked(UnparsedJSON options) NIMPL;
bool Sources::Enable::GetFullCombo(UnparsedJSON options) NIMPL;
bool Sources::Enable::GetPercentage(UnparsedJSON options) NIMPL;
bool Sources::Enable::GetFailed(UnparsedJSON options) NIMPL;
