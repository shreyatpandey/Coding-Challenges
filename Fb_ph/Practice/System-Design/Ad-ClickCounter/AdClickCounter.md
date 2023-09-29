# Ad-Click Counter
  * Functional Requirements:-
     * Report ads click counter in last 5 minutes
     * Aggregates click per ad/campaign
     * Do we need to check from where the ad click is happening? For device
     * There will be UI admin for showing ad reports
     * Will there be hot/popular ads that would cause sudden burst of traffic?
        * Feasible or not
     * How precise/accurate reporting should be?
        * 5% is tolerable

  * Non-Functional Requirements:-
     * Actual ad clicks and redirect should be pretty fast ( low latency)
     * Maximum latency should be 30 seconds for user to report
     * Scalability:- Handle many request increasing million request to billion request
     * Availability:- Following the trading 99% availability with minimum downtime.
     * Consistency:- Ads count should be consistent when viewed by various users

  * Capacity Estimations and Constraints:-
     * How many clicks per second?
        * 1 billion clicks per day
        * 100 million daily active users
        * Let's say every user click 2 ads per day
        * 
     
     * Storage Estimation:-
        * Storage for how many years ?
        * 5 years
        * Each day we need 200 M* 100 B = 20 GB
        * In one year, we would 365 * 20GB  ~ = 8 TB of Data
        * In 5 years ~ 40 Tb of data
   * API Design:
      * getReport(ad_id, starts_at, ends_at)
      * getReport(user_id, ad_id, starts_at, ends_at)
      * getReport(user_id, ad_id, start_at, ends_at

      <img width="403" alt="Screenshot 2023-09-29 at 1 25 26 PM" src="https://github.com/shreyatpandey/Coding-Challenges/assets/32083899/aa28abde-2454-438f-9f3c-9e6ca8770b49">


    * High Level Design:
      * 
