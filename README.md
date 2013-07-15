ElephantCoin - a decendent of Litecoin that combines the great features from Luckycoin (random blocks) and Florincoin (transaction message). Like Litecoin it uses scrypt as a proof of work scheme.

	- 20 seconds block time
	- Difficulty retargets every 60 blocks, with accelerated diff retarget at the beginning to prevent instamining 
	- Total coins will be around 340 millions
	- 3 confirmations for transaction, thus a zap fast 1 minute transaction confirmation
	- 30 confirmations for minted blocks
	- support transaction message
	- 50 coins per block, and with following super random blocks:
		- 1/100 chance, a random 100-500 coins block
		- 1/2,000 chance (about twice a day), a random 1000-5000 coins block
		- 1/30,000 chance (about once per week), a random 10000-20000 coins block 
	
	- The prize will be halved every 2 years.

	- The default ports are 13808 (Connect) and 13809 (RPC).



Development process
===================

Developers work in their own trees, then submit pull requests when
they think their feature or bug fix is ready.

The patch will be accepted if there is broad consensus that it is a
good thing.  Developers should expect to rework and resubmit patches
if they don't match the project's coding conventions (see coding.txt)
or are controversial.

The master branch is regularly built and tested, but is not guaranteed
to be completely stable. Tags are regularly created to indicate new
official, stable release versions of Elephant coin.

Feature branches are created when there are major new features being
worked on by several people.

From time to time a pull request will become outdated. If this occurs, and
the pull is no longer automatically mergeable; a comment on the pull will
be used to issue a warning of closure. The pull will be closed 15 days
after the warning if action is not taken by the author. Pull requests closed
in this manner will have their corresponding issue labeled 'stagnant'.

Issues with no commits will be given a similar warning, and closed after
15 days from their last activity. Issues closed in this manner will be 
labeled 'stale'. 
