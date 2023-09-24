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
  
