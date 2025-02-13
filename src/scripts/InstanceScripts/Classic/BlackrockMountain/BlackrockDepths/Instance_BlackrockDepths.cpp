/*
Copyright (c) 2014-2023 AscEmu Team <http://www.ascemu.org>
This file is released under the MIT license. See README-MIT for more information.
*/

#include "Setup.h"
#include "Instance_BlackrockDepths.h"

class BlackrockDepthsInstanceScript : public InstanceScript
{
public:
    explicit BlackrockDepthsInstanceScript(WorldMap* pMapMgr) : InstanceScript(pMapMgr){}
    static InstanceScript* Create(WorldMap* pMapMgr) { return new BlackrockDepthsInstanceScript(pMapMgr); }
};

void SetupBlackrockDepths(ScriptMgr* mgr)
{
    mgr->register_instance_script(MAP_BLACKROCK_DEPTHS, &BlackrockDepthsInstanceScript::Create);
}
