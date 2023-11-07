# Requriements
 ## Functional Requirments
   * Show the K most played songs in the past 24 hours
   * Record and count the songs as they are being played by end users

  ## Non-Functional Requirements:-
   * Consistency :- Songs being heard by different users should be the same for all regions
   * Availability:- There should be a minimum downtime of the platform when any user want to listen to song at given point of time
   * Scalability:- AS the number of user increases, support more users

# Capacity Estimations and Constraint
 # Numbers:-
   * Number of active users? 1 billion = 10^9 users
   * Number of songs hosted on server? 100 million = 100 x 10^6
   * Size of song? 5 MB
 # Storage Estimation
    * Total Audio Storage = 100 million x 5 MB = 500 TB
 # Bandidth and Traffic Estimation
  * Download speed = Total Audio Storage/(86400) = 500 TB/86400  ~ 1000 Mbp/s

 # Schema
  * Database Schema:- 
     * Database that is getting used is Casandra
     * Schema:- <br>
     {
       song_id:- 12345<br>
       hourly_timestamp:- timestamp in seconds :- 1675000<br>
       song_url: sharing<br>
       artist_name:<br>
       genre_name:<br>
     }
