# Requirements
  ## Functional Requirements
    * We should report ad click events, capture the outlcick events
    * We should be able to query the ad click events

 ## Non Functional Requirments
  * Low Latency:- Actual ad clicks and redirect should be pretty fast ( low latency )
  * Consistency:- Eventual consistency is good enough
  * Availability:- High availability for ad click counter. With minimum down time and high up time of 99%
  * Performance

# Numbers
  * Number of clicks per day:- 1 billion
  * Number of ads:- 2 million ads
  * How many clicks per second:- 1 x 10^9/(86400 second ~ 1x10^9/10 x 10^3 = 10,000 TPS
  * Per click 0.1kb of metadata is getting generated
  
  ## Storage
    * How much storage for 1 years:- 1 MB per second * 100k x 365 = 36.5 TB
    * How much storage for 10 years:- 36.5 GB x 10 = 365 TB


  ## Bandwidth
   * Bandwidth requirment:- 10,000 TPS x 0.1 kb = 1,000 kb per second = 1 MB per second
   * At peak = 50,000 TPS avg x 0.1 kb  = 5 MB per second

  ## Analytical Part
   * 100k MAU

# High Level Design
 * Browser-clicker :- User clicks browser for the ad
 * Browser-Analyst :- Mostly for the marketing analyst to give input here
 * Ad-placement service:- uuid for ad ad_id
 * CDN
 * Click Capture Service:- 30x redirection
 * Message Broker:- High volume of 10,000 TPS, can be avoided for backpressure problem
 * Request contract:- getQuery(user_id,ad_id,timestamp)
   request:<br>
     {<br>
        ad_id<br>
        uuid_of_ad<br>
        timestamp<br>
        metadata<br>
     }<br>
    
    <pr>
    response:
    30 x redirect event
    </pr>
 
 * Ad Capture Data Store:- 365 TB over 10 years
   Schema <br>
   {<br>
     uuid[ensure de-duping]:- hexadecimal <br> 
     ad_id<br>
     timestamp<br>
     metadata_about_click: {}<br>
    }<br>

  * Database:-
     Cassandra<br>
     Time-series database<br>

  * Partitioning:-
    
     
   
