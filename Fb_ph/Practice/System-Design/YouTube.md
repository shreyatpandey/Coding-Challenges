# Requirements
Let’s start with the requirements for designing a system like YouTube.

# Functional requirements
  * We require that our system is able to perform the following functions:
      * Stream videos
      * Upload videos
      * Search videos according to titles
      * Like and dislike videos
      * Add comments to videos
      * View thumbnails

# Non-functional requirements
  * It’s important that our system also meets the following requirements:
    * High availability:
         * The system should be highly available.
         * High availability requires a good percentage of uptime. Generally, an uptime of 99% and above is considered good.
    * Scalability:
       * As the number of users grows, these issues should not become bottlenecks:
          * storage for uploading content,
          * the bandwidth required for simultaneous viewing,
          * and the number of concurrent user requests should not overwhelm our application/web server.
    * Good performance: A smooth streaming experience leads to better performance overall.
    * Reliability: Content uploaded to the system should not be lost or damage
    * We don’t require strong consistency for YouTube’s design.
       * Consider an example where a creator uploads a video. Not all users subscribed to the creator’s channel should immediately get the    
         notification for uploaded content.
  # Estimations
   ## Resource Estimations
    Estimation requires the identification of important resources that we’ll need in the system.
     Hundreds of minutes of video content get uploaded to YouTube every minute. 
     Also, a large number of users will be streaming content at the same time, which means that the following resources will be required:
     Storage resources will be needed to store uploaded and processed content.
     A large number of requests can be handled by doing concurrent processing.
     This means web/application servers should be in place to serve these users.
     Both upload and download bandwidth will be required to serve millions of users.
     To convert the above resources into actual numbers, we assume the following:
        Total number of YouTube users: 1.5 billion.
        Active daily users (who watch or upload videos): 500 million.
        Average length of a video: 5 minutes.
        Size of an average (5 minute-long) video before processing/encoding (compression, format changes, and so on): 600 MB.
        Size of an average video after encoding (using different algorithms for different resolutions like MPEG-4 and VP9): 30 MB.
