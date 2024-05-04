# TE-SEM6
Engineering 6th Semester Laboratory Assignments Repository<br>
Welcome to the repository for the 6th semester laboratory assignments in the field of Engineering. This collection includes Web Development Technology, LP2 (Programming Paradigms), and Data Science and Big Data Analysis Lab.<br>

Table of Contents<br>
Web Development Technology<br>
LP2 (Programming Paradigms)<br>
Data Science and Big Data Analysis Lab<br>


For Hadoop : 

cd hadoop <br>
start-dfs.sh <br>
start-yarn.sh <br>
jps <br>

hadoop fs -mkdir  /31445 <br>
3)hadoop fs -mkdir  /31445/input  <br>
open localhost:9870 <br>
hadoop fs -put input.txt  /31445/input <br>
hadoop jar abc.jar  /31445/input  /31445/output <br>
hadoop dfs  -cat  /31445/output/*  <br>

for scala : 

val data=sc.textFile("input.txt") <br>
data.collect; <br>
val splitdata = data.flatMap(line => line.split(" "));  <br>
splitdata.collect; <br>
val mapdata = splitdata.map(word => (word,1));  <br> 
mapdata.collect;  <br>
val reducedata = mapdata.reduceByKey(_+_);  <br>
reducedata.collect; <br>

