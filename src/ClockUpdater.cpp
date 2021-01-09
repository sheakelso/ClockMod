#include "ClockUpdater.hpp"
#include "UnityEngine/GameObject.hpp"
#include "TMPro/TextMeshProUGUI.hpp"
#include <ctime>
using namespace UnityEngine;
using namespace TMPro;

DEFINE_CLASS(ClockMod::ClockUpdater);

void ClockMod::ClockUpdater::Update(){
    time_t rawtime;
    struct tm * timeinfo;
    time (&rawtime);
    timeinfo = localtime (&rawtime);

    std::string timedate = asctime(timeinfo);
    std::string time = timedate.substr(11,5);

    auto text = get_gameObject()->GetComponent<TextMeshProUGUI*>();
    text->set_text(il2cpp_utils::createcsstr(time));
}