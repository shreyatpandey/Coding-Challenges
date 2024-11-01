# Requirments
 ## Functional Requirments
   * Take submissions from contestants
   * Evaluate the submission to successful or failed
   * Rank the contestants
      * Doesn't update the contestants on the fly
      * Out of scope:- Testcases, Run
 ## Non-Functionial Requirments
   * Consistency:- The platform should have the content or question is displayed to contestants when accessed
   * Availability:- The coding platform should have high availability with minimum downtime.Perhaps <1% of downtime
   * Scalability:- The coding platform should be able to support users as it scales
     discuss the trade off

# Estimations and Constraints:-
 * How long is the contest? 90 minutes long
 * How many active contestants are present? Say 20,000
 * How many submission can contestant make for a given question? 6 submission on avg
 * How much time does submission take? 5 seconds of processing time
 * What is the making size of code? 2 kb size on average.
    It is pretty fair number
 * How many submissions are running concurrently?
    22 submission per second(TPS)
    They run for 5 seconds
    22*5 = 110 submissions running concurrently
 
 # Storage Estimatoins:-
   * Total submission per minute = 20 k* 6 = 120,000 per minute
   * 90 minute * 6 -> 5400 seconds
   * 120 k/5400 -> ~ 22 submissions per second (TPS)

 # Bandwidth Estimation:-
  22 TPS * 2 kb -> 44 kb per second
  Round of 50 kb * -> 400k bits per second
  ~ 1 MB per second

 # Number of Server Estimations:-
  How many machines for processing all those concurrent submissions?<br>
  110 submissions running concurrently<br>
  8 vCPUs each ( only 4 core)<br>
  round up to 10 threads at once<br>

 # High Level Design:-
   * Link:- https://github.com/systemdesignfightclub/SDFC/blob/main/problems/coding-competition-platform/images/diagram-screenshot.png
   * Browser-Contestant Viewing a Problem:- For contestant where the problem is loaded
   * Problem Backend Server:- 
   * Problem Metadata store:- Object store to store problem
   * Problem Object Store:- This will host unit test file for problem object store, it would be connected to CDN
   * CDN :- Hosting the problem, URL is generate from problem metadata store/ backend server
   * Submission:- Submission backend server
   * Distributed File Storage:- Where we can store submission object store from different contestants
   * Distributed Messaging Queue:-
      5 second processing time, if the link is not working, need to refresh
      This is connected to submission backend server
   * Submission Evaluation Task Runners:-
      Connected from distributed messaging queue
       Async functions
   * Web Sockets:-
      1. Web sockets connects submission backend server to browser contestant viewing problem
      2. Web sockets also connects submission evaluation task runners to submission backend server
   * Flow from code submission back to server:-<br>
    * 100 ms to get response after submitting the code<br>
    * Total RTT = 200 ms<br>
   * Distrubution of machines:-<br>
     11 machines for submission evaluation task runner<br>
     At most 1 machine for the submission of backend server<br>
     5 thread running concurrently<br>
     3 machines of m5.large, where different instances can run<br>
     put 2 machines( m5.large or m5.medium) in each region for submission backend server<br>
  * Result metadata store:-
    Submission evaluation task runners would be connected to this
  * Some distributed data store like NoSQL over result metadata store
  * Ranking Map Reduce job:- Pull result from NoSQL database , and then parallelize it
  * Browser-Contestant View Ranking:-
  * Leadership display service
  * Leadership Database:- Ranking map reduce job is connected to leaderboard DB
  * User Info DB:- this is connected to ELO Map Reduce Job
  * Browser-Viewing USer Page
  * User display service

 # DB Schema
  * Result Metadata store:-<br>
    From submission evaluation task runners gets connected to result metadata store<br>
    **Result Metdata Schema**:-<br>
     {<br>
       timestamp:- 17900000<br>
       user_id:- 123000 - indicating who made the submission<br>
       submission_uuid:- abcdef-12-lmnopq<br>
       url_link:- distributed file storage link<br>
       isPassing: true<br>
     }<br>
    Ranking Map Reduce Jobs<br>
    1] find timestamps for first passing result of each user for each problem (find timestamp with least value)<br>
    2] Count up the number of failed submissions from prior to first passing result timestamp<br>
    3] Sort all the users by points scored and then by order of timestamp with failure penalty applied
    3 different jobs in a row<br>

    **Leaderboard schema**:-<br>
    {<br>
       user_id:- 123000<br>
       rank:- 1500<br>
       contest_id: 150 ** - (sort key/secondary index)<br>
       submissions: { successful_submission_link:- url, fail_count: 3, success_timestamp: 167000 }<br>
    }<br>

    **user info schema**:-<br>
    {<br>
       user_id: 123000<br>
       contestant_rank : { contest_id: 160, contest_rank: 2300}<br>
       global_rank: 25,000<br>
    }<br>

    **Problem store schema**:<br>
    {<br>
      problem_id: 2300<br>
      url_prompt_link:<br>
    }<br>

 # Cache: 
  * Caching on data-store
  * Intellgent caching from the region where there is a high traffic
  * Higher traffic from Asian Region

 # Hot-Key Problem:
  * Consistent Hashing:-
     To resolve hot-spot or hot-key problem depending on the contest_id we can use consistent hashing
     
    
    
    

     
     
     
     
  

  

   
