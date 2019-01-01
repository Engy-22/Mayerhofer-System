# Mayerhofer System
College football ranking algorithm. Ranks teams based on who they play (power 5, G5, or FCS), record of the opponent, and how much a team wins/loses by.

# Ways to run:
* Print FBS rankings:
	* Run ./mayerhofer\_rankings &lt;team\_file> &lt;scores\_file>
	* Prints the rankings of all the P5/G5 teams in the &lt;team\_file>
* Predict winners of future games:
	* Run ./mayerhofer\_rankings &lt;team\_file> &lt;scores\_file> &lt;predictions\_file> P
	* Prints the games in the &lt;predictions\_file>
* Check prediction success of games:
	* Run ./mayerhofer\_rankings &lt;team\_file> &lt;scores\_file> &lt;results\_file> R
	* In &lt;scores\_file> there should only be scores leading up to the games in &lt;results\_file>
	* Prints the games in the &lt;results\_file> and whether they were predicted correctly or not

# Files:

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

## Predictions file
1. As you did for the Scores file, go to sports-reference cfb and get the games you want to predict
2. Copy the games into the Predictions file
3. Make sure that the games in the prediction file all come after the games in the Scores file

## Results file
1. As you did for the Scores file, go to sports-reference fb and get the games you want to check were predicted right or wrong
2. Copy the games into the Prediction_Results file
3. Make sure that the games in the results file all come after the games in the Scores file
