/*
Copyright (c) 2014-2023 AscEmu Team <http://www.ascemu.org>
This file is released under the MIT license. See README-MIT for more information.
*/

#pragma once

#include <mutex>
#include <vector>

#include "Channel.hpp"
#include "Storage/DBC/DBCStructures.hpp"

class SERVER_DECL ChannelMgr
{
private:
    ChannelMgr() = default;
    ~ChannelMgr() = default;

public:
    ChannelMgr(ChannelMgr&&) = delete;
    ChannelMgr(ChannelMgr const&) = delete;
    ChannelMgr& operator=(ChannelMgr&&) = delete;
    ChannelMgr& operator=(ChannelMgr const&) = delete;

    static ChannelMgr& getInstance();

    void initialize();
    void finalize();

    void loadConfigSettings();
    void setSeperatedChannels(bool enabled);

    std::shared_ptr<Channel> getOrCreateChannel(std::string name, Player const* player, uint32_t typeId);
    void removeChannel(std::shared_ptr<Channel> channel);

    std::shared_ptr<Channel> getChannel(std::string name, Player const* player) const;
    std::shared_ptr<Channel> getChannel(std::string name, uint32_t team) const;

    bool canPlayerJoinDefaultChannel(Player const* player, DBC::Structures::AreaTableEntry const* areaEntry, DBC::Structures::ChatChannelsEntry const* channelDbc) const;
    std::string generateChannelName(DBC::Structures::ChatChannelsEntry const* channelDbc, DBC::Structures::AreaTableEntry const* areaEntry) const;

    std::vector<std::string> m_bannedChannels;
    std::vector<std::string> m_minimumChannel;

private:
    typedef std::map<std::string, std::shared_ptr<Channel>> ChannelList;
    ChannelList m_channelList[2];

    bool m_seperateChannels = false;

    mutable std::mutex m_mutexConfig;
    mutable std::mutex m_mutexChannels;
};

#define sChannelMgr ChannelMgr::getInstance()
