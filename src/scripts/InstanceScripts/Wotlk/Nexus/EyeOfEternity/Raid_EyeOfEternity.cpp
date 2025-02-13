/*
Copyright (c) 2014-2023 AscEmu Team <http://www.ascemu.org>
This file is released under the MIT license. See README-MIT for more information.
*/

#include "Setup.h"
#include "Raid_EyeOfEternity.h"

class EyeOfEternityInstanceScript : public InstanceScript
{
public:
    explicit EyeOfEternityInstanceScript(WorldMap* pMapMgr) : InstanceScript(pMapMgr){}
    static InstanceScript* Create(WorldMap* pMapMgr) { return new EyeOfEternityInstanceScript(pMapMgr); }
};

void SetupEyeOfEternity(ScriptMgr* mgr)
{
    mgr->register_instance_script(MAP_THE_EYE_OF_ETERNITY, &EyeOfEternityInstanceScript::Create);
}
