# Ad-Click Counter
  * Functional Requirements:-
    * We should capture ad click event
    * We should be able to query the ad click events

  * Non-Functional Requirements:-
     * Actual ad clicks and redirect should be pretty fast ( low latency)

  * Capacity Estimations and Constraints:-
     * How many clicks per second?
        * 1 billion clicks per day
        * 1 billion clicks per day/ 100k = 10,000 TPS
     * How much bandwidth is required?
        * 
     * Storage Estimation:-
        * Storage for how many years ?
           10,000 TPS avg * 0.1 kb per click = 0.1kb of write
           1,000 kb per second

      <img width="403" alt="Screenshot 2023-09-29 at 1 25 26 PM" src="https://github.com/shreyatpandey/Coding-Challenges/assets/32083899/aa28abde-2454-438f-9f3c-9e6ca8770b49">

