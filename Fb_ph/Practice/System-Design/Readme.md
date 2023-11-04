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
   * Uploading / Downloading :- For seconds = 24x60x60 = 86400 sec
   * Speed:- (Data-Stored in TB)/(86400 sec) = (10 TB)/(86400) ~ 1000 MBps or 1000 GBPs depending upon total storage
   * Sometimes take into consideration, Read/Write Ratio :- 100:1 or 1:100 for upload / download speed
* Server's Estimation:-
  * Numbers of Servers = Number of Active Users/(Queries or Request per second)
  * Keep Queries or Request per second = 10,000/second
  * Number of Servers range from 10,000 to 20,000 servers
* Conversion :- <br>
   1. 1 TB = 10^12 Bytes<br>
   2. 1 PB = 10^15 Bytes<br>

# Database:-
  * Relational Database:- <br>
    1. Proximity Server/Yelp
    2. Web Crawler
    3. Whatsapp
    4. Instgram

  * Non-Relational Database:- <br>
    1. Youtube <br>
    2. Typeahead Suggestion
    3. Online Price Tracker
    4. Ad Counter
    5. Online Coding Platform

# Important Numbers every engineer should know<br>
Latency Comparison Numbers
--------------------------
L1 cache reference                           0.5 ns<br>
Branch mispredict                            5   ns<br>
L2 cache reference                           7   ns                      14x L1 cache<br>
Mutex lock/unlock                           25   ns<br>
Main memory reference                      100   ns                      20x L2 cache, 200x L1 cache<br>
Compress 1K bytes with Zippy            10,000   ns       10 us<br>
Send 1 KB bytes over 1 Gbps network     10,000   ns       10 us<br>
Read 4 KB randomly from SSD*           150,000   ns      150 us          ~1GB/sec SSD<br>
Read 1 MB sequentially from memory     250,000   ns      250 us<br>
Round trip within same datacenter      500,000   ns      500 us<br>
Read 1 MB sequentially from SSD*     1,000,000   ns    1,000 us    1 ms  ~1GB/sec SSD, 4X memory<br>
HDD seek                            10,000,000   ns   10,000 us   10 ms  20x datacenter roundtrip<br>
Read 1 MB sequentially from 1 Gbps  10,000,000   ns   10,000 us   10 ms  40x memory, 10X SSD<br>
Read 1 MB sequentially from HDD     30,000,000   ns   30,000 us   30 ms 120x memory, 30X SSD<br>
Send packet CA->Netherlands->CA    150,000,000   ns  150,000 us  150 ms<br>

Notes<br>
-----
1 ns = 10^-9 seconds<br>
1 us = 10^-6 seconds = 1,000 ns<br>
1 ms = 10^-3 seconds = 1,000 us = 1,000,000 ns<br>
    
