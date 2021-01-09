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

void ToggleMethod(ClockMod::ClockViewController* parent, bool newValue){
    getConfig().config["insong"].SetBool(newValue);
}

void ClockMod::ClockViewController::DidActivate(bool firstActivation, bool addedToHierarchy, bool screenSystemEnabling){
    if(firstActivation){

        get_gameObject()->AddComponent<Touchable*>();
        GameObject* container = QuestUI::BeatSaberUI::CreateScrollableSettingsContainer(get_transform());

        UnityEngine::Events::UnityAction_1<bool>* onSettingChange = il2cpp_utils::MakeDelegate<UnityEngine::Events::UnityAction_1<bool>*>(
            classof(UnityEngine::Events::UnityAction_1<bool>*), this, ToggleMethod
        );

        QuestUI::BeatSaberUI::CreateToggle(container->get_transform(), "Show During Song", getConfig().config["insong"].GetBool(), onSettingChange);
    }
}

void ClockMod::ClockViewController::DidDeactivate(bool removedFromHierarchy, bool systemScreenDisabling){
    getConfig().Write();
}
