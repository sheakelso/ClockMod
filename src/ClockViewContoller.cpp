#include "ClockViewController.hpp"
#include "main.hpp"

#include "questui/shared/BeatSaberUI.hpp"

#include "UnityEngine/UI/VerticalLayoutGroup.hpp"
#include "UnityEngine/Events/UnityAction_1.hpp"
#include "UnityEngine/GameObject.hpp"
#include "HMUI/Touchable.hpp"
#include "HMUI/ScrollView.hpp"
using namespace UnityEngine::UI;
using namespace UnityEngine;
using namespace HMUI;

DEFINE_CLASS(ClockMod::ClockViewController);

void InSongToggle(ClockMod::ClockViewController* parent, bool newValue) {
    getConfig().config["insong"].SetBool(newValue);
}
void FormatToggle(ClockMod::ClockViewController* parent, bool newValue) {
    getConfig().config["12Toggle"].SetBool(newValue);
}
void SecToggle(ClockMod::ClockViewController* parent, bool newValue) {
    getConfig().config["SecToggle"].SetBool(newValue);
}

void ClockMod::ClockViewController::DidActivate(bool firstActivation, bool addedToHierarchy, bool screenSystemEnabling) {
    if (firstActivation) {

        get_gameObject()->AddComponent<Touchable*>();
        GameObject* container = QuestUI::BeatSaberUI::CreateScrollableSettingsContainer(get_transform());

        UnityEngine::Events::UnityAction_1<bool>* onInSongSettingChange = il2cpp_utils::MakeDelegate<UnityEngine::Events::UnityAction_1<bool>*>(
            classof(UnityEngine::Events::UnityAction_1<bool>*), this, InSongToggle
            );

        QuestUI::BeatSaberUI::CreateToggle(container->get_transform(), "Show During Song", getConfig().config["insong"].GetBool(), onInSongSettingChange);

        UnityEngine::Events::UnityAction_1<bool>* onFormatSettingChange = il2cpp_utils::MakeDelegate<UnityEngine::Events::UnityAction_1<bool>*>(
            classof(UnityEngine::Events::UnityAction_1<bool>*), this, FormatToggle
            );
        QuestUI::BeatSaberUI::CreateToggle(container->get_transform(), "24/12 Toggle", getConfig().config["12Toggle"].GetBool(), onFormatSettingChange);

        UnityEngine::Events::UnityAction_1<bool>* onSecSettingChange = il2cpp_utils::MakeDelegate<UnityEngine::Events::UnityAction_1<bool>*>(
            classof(UnityEngine::Events::UnityAction_1<bool>*), this, SecToggle
            );
        QuestUI::BeatSaberUI::CreateToggle(container->get_transform(), "Toggle Seconds", getConfig().config["SecToggle"].GetBool(), onSecSettingChange);
    }
}

void ClockMod::ClockViewController::DidDeactivate(bool removedFromHierarchy, bool systemScreenDisabling) {
    getConfig().Write();
}