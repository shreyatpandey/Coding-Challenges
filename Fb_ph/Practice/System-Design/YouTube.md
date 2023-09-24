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
     * Upload videos
     * Stream videos
     * Search videos
     * View thumbnails
     * Like or dislike videos
     * Comment on videos

   ### Upload Video
   The **POST method** can upload a video to the /uploadVideo API:
   **uploadVideo(user_id, video_file, category_id, title, description, tags, default_language, privacy_settings)**
   Let’s take a look at the description of the following parameters here.
   Parameter

   ### Stream Video
   The **GET method** is best suited for the /streamVideo API:
   **streamVideo(user_id, video_id, screen_resolution, user_bitrate, device_chipset)**
   The server will store different qualities of the same video in its storage and serve users based on their transmission rate.

   ### Search Videos
   The **/searchVideo** API uses the GET method:
   **searchVideo(user_id, search_string, length, quality, upload_date)**

   ### View Thumbnails
   We can use the GET method to access the **/viewThumbnails** API:
   **viewThumbnails(user_id, video_id)**

   ### Like and Dislike Video
   The like and dislike API uses the POST method to register a like/dislike. As shown below, it’s fairly simple.
   **likeDislike(user_id, video_id, like)**
   We can use the same API for the like and dislike functionality. Depending on what is passed as a parameter to the like field, we can update the   database accordingly—that is, 0 for like and a 1 for dislike

 Comment video
Much like the like and dislike API, we only have to provide the comment string to the API. This API will also use the POST method.
commentVideo(user_id, video_id, comment_text)
Parameter	Description
comment_text	This refers to the text that is typed by the user on the particular video.
Storage schema
Each of the above features in the API design requires support from the database—we’ll need to store the details above in our storage schema to provide services to the API gateway.
Storage schema
Note: Much of the underlying details regarding database tables that can be mapped to services provided by YouTube have been omitted for simplicity. For example, one video can have different qualities and that is not mentioned in the “Video” table.
Detailed design
Now, let’s get back to our high-level design and see if we can further explore parts of the design. In particular, the following areas require more discussion:
•	Component integration: We’ll cover some interconnections between the servers and storage components to better understand how the system will work.
•	Thumbnails: It’s important for users to see some parts of the video through thumbnails. Therefore, we’ll add thumbnail generation and storage to the detailed design.
•	Database structure: Our estimation showed that we require massive storage space. We also require storing varying types of data, such as videos, video metadata, and thumbnails, each of which demands specialized data storage for performance reasons. Understanding the database details will enable us to design a system with the least possible lag.
Let’s take a look at the diagram below. We’ll explain our design in two steps, where the first looks at what the newly added components are, and the second considers how they coordinate to build the YouTube system.
Detailed design components
Since we highlighted the requirements of smooth streaming, server-level details, and thumbnail features, the following design will meet our expectations. Let’s explain the purpose of each added component here:
•	Load balancers: To divide a large number of user requests among the web servers, we require load balancers.
•	Web servers: Web servers take in user requests and respond to them. These can be considered the interface to our API servers that entertain user requests.
•	Application server: The application and business logic resides in application servers. They prepare the data needed by the web servers to handle the end users’ queries.
•	User and metadata storage: Since we have a large number of users and videos, the storage required to hold the metadata of videos and the content related to users must be stored in different storage clusters. This is because a large amount of not-so-related data should be decoupled for scalability purposes.
•	Bigtable: For each video, we’ll require multiple thumbnails. Bigtable is a good choice for storing thumbnails because of its high throughput and scalability for storing key-value data. Bigtable is optimal for storing a large number of data items each below 10 MB. Therefore, it is the ideal choice for YouTube’s thumbnails.
•	Upload storage: The upload storage is temporary storage that can store user-uploaded videos.
•	Encoders: Each uploaded video requires compression and transcoding into various formats. Thumbnail generation service is also obtained from the encoders.
•	CDN and colocation sites: CDNs and colocation sites store popular and moderately popular content that is closer to the user for easy access. Colocation centers are used where it’s not possible to invest in a data center facility due to business reasons.
Detailed design of YouTube’s components
Design flow and technology usage
Now that we understand the purpose of every component, let’s discuss the flow and technology used in different components in the following steps:
1.	The user can upload a video by connecting to the web servers. The web server can run Apache or Lighttpd. Lighttpd is preferable because it can serve static pages and videos due to its fast speed.
2.	Requests from the web servers are passed onto application servers that can contact various data stores to read or write user, videos, or videos’ metadata. There are separate web and application servers because we want to decouple clients’ services from the application and business logic. Different programming languages can be used on this layer to perform different tasks efficiently. For example, the C programming language can be used for encryption. Moreover, this gives us an additional layer of caching, where the most requested objects are stored on the application server while the most frequently requested pages will be stored on the web servers.
3.	Multiple storage units are used. Let’s go through each of these:
I.	Upload storage is used to store user-uploaded videos before they are temporarily encoded.
II.	User account data is stored in a separate database, whereas videos metadata is stored separately. The idea is to separate the more frequently and less frequently accessed storage clusters from each other for optimal access time. We can use MySQL if there are a limited number of concurrent reads and writes. However, as the number of users—and therefore the number of concurrent reads and writes—grows, we can move towards NoSQL types of data management systems.
III.	Since Bigtable is based on Google File System (GFS), it is designed to store a large number of small files with low retrieval latency. It is a reasonable choice for storing thumbnails.
4.	The encoders generate thumbnails and also store additional metadata related to videos in the metadata database. It will also provide popular and moderately popular content to CDNs and colocation servers, respectively.
5.	The user can finally stream videos from any available site.
Note: Because YouTube is storage intensive, sharding different storage services will effectively come into play as we scale and do frequent writes on the database. At the same time, Bigtable has multiple cache hierarchies. If we combine that with GFS, web- and application-level caching will further reduce the request processing latency.
YouTube search
Since YouTube is one of the most visited websites, a large number of users will be using the search feature. Even though we have covered a building block on distributed search, we’ll provide a basic overview of how search inside the YouTube system will work.
Each new video uploaded to YouTube will be processed for data extraction. We can use a JSON file to store extracted data, which includes the following:
•	Title of the video.
•	Channel name.
•	Description of the video.
•	The content of the video, possibly extracted from the transcripts.
•	Video length.
•	Categories.
Each of the JSON files can be referred to as a document. Next, keywords will be extracted from the documents and stored in a key-value store. The key in the key-value store will hold all the keywords searched by the users, while the value in the key-value store will contain the occurrence of each key, its frequency, and the location of the occurrence in the different documents. When a user searches for a keyword, the videos with the most relevant keywords will be returned.
An abstraction of how YouTube search works
![image](https://github.com/shreyatpandey/Coding-Challenges/assets/32083899/33b4a59e-439b-4df4-95ec-1d89057436fa)





    

 
