# Requirements
  ## Functional Requirements
    * We should report ad click events, capture the outlcick events
    * We should be able to query the ad click events

 ## Non Functional Requirments
  * Low Latency
  * Consistency
  * Availability
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

# High Level Design
 * 
