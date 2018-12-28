# Mayerhofer System
College football ranking system. Ranks teams based scores of games throughout the season.

# How to generate Mayerhofer rankings for a season:

## Scores file
1. Go to https://www.sports-reference.com/cfb
2. Years > pick a year > Schedule & Scores
3. Find the "Share & more" dropdown, select "Get table as CSV (for Excel)"
4. Copy as many scores as you'd like into a Scores file
	* **IGNORE THE FIRST LINE WITH Rk,Wk,Date,Time...etc.**

## Teams file
1. Format: Team name (string),P/G/F (Power 5, Group of 5, FCS)
	* If you don't know if a team is P5, G5, or FCS, you can look it up online
	* I've provided Teams_2017 and Teams_2018 for reference on how the file should look. Feel free to copy the teams over, but make sure the P/G/F is correct
2. **IMPORTANT: Make sure the team name in the Teams file is the same as it appears on the cfb reference schedule & results page**

## Generating the rankings
* In your terminal, run make to generate the mayerhofer_rankings executable
* Generate the rankings by running ./mayerhofer_rankings <teams_file> <scores_file>
* run make clean to remove the .o files
