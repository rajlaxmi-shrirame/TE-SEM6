# TE-SEM6
Engineering 6th Semester Laboratory Assignments Repository<br>
Welcome to the repository for the 6th semester laboratory assignments in the field of Engineering. This collection includes Web Development Technology, LP2 (Programming Paradigms), and Data Science and Big Data Analysis Lab.<br>

Table of Contents<br>
Web Development Technology<br>
LP2 (Programming Paradigms)<br>
Data Science and Big Data Analysis Lab<br>


For Hadoop : 

cd hadoop
start-dfs.sh
start-yarn.sh
jps

hadoop fs -mkdir  /31445
3)hadoop fs -mkdir  /31445/input 
open localhost:9870
hadoop fs -put input.txt  /31445/input 
hadoop jar abc.jar  /31445/input  /31445/output
hadoop dfs  -cat  /31445/output/* 
