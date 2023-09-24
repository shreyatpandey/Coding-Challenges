![image](https://github.com/shreyatpandey/Coding-Challenges/assets/32083899/da46f323-cb38-40c0-bb4c-ada950afe58d)# Requirements
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
   
   ## Storage Estimation
    To find the storage needs of YouTube, we have to estimate the total number of videos and the length of each video uploaded to YouTube per minute. 
    Let’s consider that 500 hours worth of content is uploaded to YouTube in one minute. Since each video of 30 MB is 5 minutes long, we require
    1 minute to store the video
    Totalstorage : Total storage requirement.
    Totalupload/min : Total content uploaded (in minutes) per minute.
    Storagemin : Storage required for each minute of content
    Then, the following formula is used to compute the storage:
    Totalstorage=Totalupload/min×Storagemin

   ## Bandwidth Estimation
    A lot of data transfer will be performed for streaming and uploading videos to YouTube. This is why we need to calculate our bandwidth estimation     too. Assume the upload:view ratio is 1:300—that is, for each uploaded video, we have 300 video views per second. We’ll also have to keep in mind      that when a video is uploaded, it is not in compressed format, while viewed videos can be of different qualities. Let’s estimate the bandwidth    
    required for uploading the videos.
    We assume:
    Totalbandwidth: Total bandwidth required.
    Totalcontent: Total content (in minutes) uploaded per minute.
    Sizeminute: Transmission required (in MBs) for each minute of content.
    Then, the following formula is used to do the computation below:
    Totalbandwidth=Totalcontent_transferred×Sizeminute
    
  # High Level Design
  The high-level design shows how we’ll interconnect the various components we identified in the previous lesson. We have started developing a     
  solution to support the functional and non-functional requirements with this design
  The workflow for the abstract design is provided below:

  The user uploads a video to the server.
  The server stores the metadata and the accompanying user data to the database and, at the same time, hands over the video to the encoder for    encoding (see 2.1 and 2.2 in the illustration above).
The encoder, along with the transcoder, compresses the video and transforms it into multiple resolutions (like 2160p, 1440p, 1080p, and so on). The videos are stored on blob storage (similar to GFS or S3).
Some popular videos may be forwarded to the CDN, which acts as a cache.
The CDN, because of its vicinity to the user, lets the user stream the video with low latency. However, CDN is not the only infrastructure for serving videos to the end user, which we will see in the detailed design.

   ## API DESIGN
   Let’s understand the design of APIs in terms of the functionalities we’re providing. We’ll design APIs to translate our feature set into technical specifications. In this case, REST APIs can be used for simplicity and speed purposes. Our API design section will help us understand how the      
   client will request services from the back-end application of YouTube. Let’s develop APIs for each of the following features:
     Upload videos
     Stream videos
     Search videos
     View thumbnails
     Like or dislike videos
     Comment on videos

   ## Upload Video
   The **POST method** can upload a video to the /uploadVideo API:
   **uploadVideo(user_id, video_file, category_id, title, description, tags, default_language, privacy_settings)**
   Let’s take a look at the description of the following parameters here.
   Parameter

   ## Stream Video
   The **GET method** is best suited for the /streamVideo API:
   **streamVideo(user_id, video_id, screen_resolution, user_bitrate, device_chipset)**
   The server will store different qualities of the same video in its storage and serve users based on their transmission rate.

   ## Search Videos
   The **/searchVideo** API uses the GET method:
   **searchVideo(user_id, search_string, length, quality, upload_date)**

   ## View Thumbnails
   We can use the GET method to access the **/viewThumbnails** API:
   **viewThumbnails(user_id, video_id)**

   ## Like and Dislike Video
   The like and dislike API uses the POST method to register a like/dislike. As shown below, it’s fairly simple.
   **likeDislike(user_id, video_id, like)**
   We can use the same API for the like and dislike functionality. Depending on what is passed as a parameter to the like field, we can update the   database accordingly—that is, 0 for like and a 1 for dislike




    

 
