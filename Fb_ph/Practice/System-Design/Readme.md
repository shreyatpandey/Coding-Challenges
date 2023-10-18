# Links:-
  * https://medium.com/the-interview-sage/top-facebook-system-design-interview-questions-ec976c6cdaa9
  * Good Github Link:- https://github.com/systemdesignfightclub/SDFC/tree/main/problems
  * System Design Drawing:- https://excalidraw.com/

# Tip:-
  * Keep last 5 minute for thorough evaluation of non-functional requirements
  * Clarify for number of active users, number of daily active users, content length
  * Make sure to touch upon data partitioning, replication, consistent hashing in every god damn topic

# Rough Estimations:-
 * Number of User? 1 billion
 * Number of Daily Active Users? 1 million or 100 million
 * Number of years to store? 5 years or 5 x 365 = 1825
 * Storage Estimation :-
   * For video :- 1 MB or 10 MB or 100 MB
   * Thumbnail:- 10 Kb
   * Image:- 10 MB or 100 MB
   * Text:- 100 Bytes
   * Total Storage Estimation:- 1 TB or 10 TB or 1 PB or 10 PB
* Bandwidth/Traffic Estimatino:-
   * Uploading / Downloading :- For seconds = 24*60*60 = 86400 sec
   * Speed:- (Data-Stored in TB)/(86400 sec) = (10 TB)/(86400) ~ 1000 MBps or 1000 GBPs depending upon total storage
   * Sometimes take into consideration, Read/Write Ratio :- 100:1 or 1:100 for upload / download speed
* Server's Estimation:-
  * Numbers of Servers = Number of Active Users/(Queries or Request per second)
  * Keep Queries or Request per second = 10,000/second
  * Number of Servers range from 10,000 to 20,000 servers
    
