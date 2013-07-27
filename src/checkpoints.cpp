// Copyright (c) 2009-2012 The Bitcoin developers
// Copyright (c) 2011-2012 Litecoin Developers
// Copyright (c) 2013 ElephantCoin Developers
// Distributed under the MIT/X11 software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#include <boost/assign/list_of.hpp> // for 'map_list_of()'
#include <boost/foreach.hpp>

#include "checkpoints.h"

#include "main.h"
#include "uint256.h"

namespace Checkpoints
{
    typedef std::map<int, uint256> MapCheckpoints;

    //
    // What makes a good checkpoint block?
    // + Is surrounded by blocks with reasonable timestamps
    //   (no blocks before with a timestamp after, none after with
    //    timestamp before)
    // + Contains no strange transactions
    //

	// no checkpoint now, can be added in later releases
    static MapCheckpoints mapCheckpoints =
            boost::assign::map_list_of
            (    1, uint256("0xa9ad33dce143c0074122e84786e715e44226df070baa1ffb0a74c325e035114a"))
            (  101, uint256("0x5555b57a8b8f109766c5160a030dc5dc3f3ec3132c1094bc677b32dfa64a3a5f"))
            ( 1001, uint256("0x56e74fe30a2f825ebb62705e5a40862ff5c4509feea97e3853270075624f6156"))
            (10001, uint256("0x910c90a245fd8be594c7d025b8b8beb7336048f2e6b0b96c21a863aaa071ae5a"))
            (20001, uint256("0x3f777e38449751c2d160ac50e15a57de4c9c6c26c405112c6c5219f68c2e896c"))
			(25000, uint256("0xbab7747ccd58c78c55549189235a842c27591128b9a2d062bc572a081b4b5308"))
			(36492, uint256("0x2458199c5fbba8b65a004c1bede5c6af9b5e562baac7105b7731bcc077684435"))
			;


    bool CheckBlock(int nHeight, const uint256& hash)
    {
        if (fTestNet) return true; // Testnet has no checkpoints

        MapCheckpoints::const_iterator i = mapCheckpoints.find(nHeight);
        if (i == mapCheckpoints.end()) return true;
        return hash == i->second;
    }

    int GetTotalBlocksEstimate()
    {
        if (fTestNet) return 0;
	
        return mapCheckpoints.rbegin()->first;
    }

    CBlockIndex* GetLastCheckpoint(const std::map<uint256, CBlockIndex*>& mapBlockIndex)
    {
        if (fTestNet) return NULL;

        BOOST_REVERSE_FOREACH(const MapCheckpoints::value_type& i, mapCheckpoints)
        {
            const uint256& hash = i.second;
            std::map<uint256, CBlockIndex*>::const_iterator t = mapBlockIndex.find(hash);
            if (t != mapBlockIndex.end())
                return t->second;
        }
        return NULL;
    }
}
