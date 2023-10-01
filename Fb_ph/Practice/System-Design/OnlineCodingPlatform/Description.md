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
  How many machines for processing all those concurrent submissions?
   110 submissions running concurrently
   8 vCPUs each ( only 4 core)
   round up to 10 threads at once

 # High Level Design:-
  

  

   
