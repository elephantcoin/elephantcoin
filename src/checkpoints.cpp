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

	// no checkpoint now, can be added in later releases
    static MapCheckpoints mapCheckpoints =
            boost::assign::map_list_of
            (     1, uint256("0xa9ad33dce143c0074122e84786e715e44226df070baa1ffb0a74c325e035114a"))
            (   101, uint256("0x5555b57a8b8f109766c5160a030dc5dc3f3ec3132c1094bc677b32dfa64a3a5f"))
            ( 10001, uint256("0x910c90a245fd8be594c7d025b8b8beb7336048f2e6b0b96c21a863aaa071ae5a"))
			( 36492, uint256("0x2458199c5fbba8b65a004c1bede5c6af9b5e562baac7105b7731bcc077684435"))
			( 89136, uint256("0x6087a054586c304c2cd6f1ee282747bea309ccbeaaf1b114c411c761ac91b7ae"))
			(100001, uint256("0xe23d8facfdea566e464255b03f933632a21612da7a2643d4155ecdeb476afc44"))
			(137448, uint256("0xd83b43497b9f74d821cb5c575f4f71392c5db1facdbd7b4b514f3f996c2de0b2"))
			(178549, uint256("0x70710816bd11aa9f9643b21e23b3708240b0ec2dadcac7d96ddd1474cc251bfd"))
			(200001, uint256("0x8378dc13be41283851554004cfdbe24e39fc94f55df582e6ed7cc6703e1f701f"))
			(217533, uint256("0xe95b6afc14318ff39f69a4ac931ea3a1b75b693e4d899478bba6ff622da597a5"))
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
