# Twilight Imperium Drafting

Resources used for the draft before playing the board game Twillight Imperium 4th edition.

## How to run (Windows)

1. Install a C++ compiler, for example MSYS2
2. Add the executable to the path. The default path for MSYS2 should be C:\msys64\ucrt64\bin
3. Open a terminal, navigate to this folder and run the script: `g++ compDraft.cpp -o compDraft`

## Description of content

This repository includes the script compDraft.cpp which is used to randomize order in draft and to distribute the factions into group.
Before using compDraft, the "Player X" placeholder values should be changed to the names of the actual players.
The script outputs a CSV file such that the output can be copy pasted to the Competetive Draft spreadsheet.

The project also includes the spreadsheet Competitive Draft which is used during the draft. The results from compDraft are used to initialize the spreadsheet.
Also an image from keeganw.github.io/ti4 is edited with borders and numbers to define the slices.

### Rules for competitive draft

#### Pre draft stream

1. Randomise the map through https://keeganw.github.io/ti4/?settings=F60009009FFF
   Settings: 6-Normal-Slice-Balanced
2. Calculate value of each slice by taking max of resource/influence for each planet and sum over the entire slice. Use a coefficient of 0.5 when adding the tile that is equally close to your left neighbour.
3. If the difference between the highest and the lowest slice is more than 2, exchange a tile from the highest valued slice with a tile from the lowest valued slice in order to equalise the two slices as much as possible. Never exchange tiles affected by the 0.5 coefficient. Prioritise exchanging as little value as possible. Repeat until the difference in value is max 2.
4. If two wormholes of the same type are present in a slice, exchange one of them with an empty space.
5. Randomise picking order.
6. Randomise the factions into 6 groups that are as similar in size as possible. When a faction is picked from a group, the other factions of the group are considered banned.

#### Competitive draft

1. In order every player picks one of the following three options: their faction, their slice or their position relative to the speaker token. If they pick a slice or a position relative to the speaker, they must also ban a faction. They can’t ban the last faction in a group and they can’t ban a faction that has already been banned. If they have no legal ban options, they will skip the banning.
2. In reverse order every player picks one of the two options they did not pick last turn and possibly ban a faction.
3. In reverse order every player picks the option they have not picked so far and possibly bans a faction.
4. Fix rule violations.
   If two or more anomalies are connected after the draft, then exchange one anomalie with an empty space that falsifies the condition. Repeat until no red areas are adjacent.
   If two connected wormholes are adjacent, switch the lone wormhole with an empty space tile that falsifies the condition. Repeat until no connected wormholes are adjacent.

A “slice” is defined as the 5 tiles that start around your homeplanet. This includes the four tiles that are closer to your home system than any other home system. As well as the tile that is both 2 steps from your home system and two tiles from the player to your left’s home system.

Always choose higher numbered tiles or slices when choosing, prioritising or ordering.

![alt text](https://github.com/PotentialKillScreen/ti4/blob/main/Example%20of%20Competitive%20draft.png)
