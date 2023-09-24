# Introduction
  A web crawler is an Internet bot that systematically scours the world wide web (WWW) for content, starting its operation from a pool of seed URLs.
  This process of acquiring content from the WWW is called crawling. 
  It further saves the crawled content in the data stores. 
  The process of efficiently saving data for subsequent use is called storing.
  This is the first step that’s performed by search engines; the stored data is used for indexing and ranking purposes.
  This specific design problem is limited to web crawlers and doesn’t include explanations of the later stages of indexing and ranking in the search engines.

# Additional Benefits
  The additional utilities of a web crawler are as follows:
  
  Web pages testing: We use web crawlers to check the validity of the links and structures of web pages.
  
  Web page monitoring: We use web crawlers to monitor the content or structure updates on web pages.
  
  Site mirroring: Web crawlers are an effective way to mirror popular websites.
  
  Copyright infringement check: Web crawlers fetch content and check for copyright infringement issues.
  
  In this chapter, we’ll design a web crawler and evaluate how it fulfills the functional and non-functional requirements.
  
  The output of the crawling process is the data that’s the input for the subsequent processing phases—data cleaning, indexing, page relevance using algorithms like page ranks, and analytics. To learn about some of these subsequent stages, refer to our chapter on distributed search.

# Requirements
 Let’s highlight the functional and non-functional requirements of a web crawler.
 ## Functional Requirements
  These are the functionalities a user must be able to perform:

  Crawling: The system should scour the WWW, spanning from a queue of seed URLs provided initially by the system administrator.
  
  Storing: The system should be able to extract and store the content of a URL in a blob store. This makes that URL and its content processable by   
  the search engines for indexing and ranking purposes.
  
  Scheduling: Since crawling is a process that’s repeated, the system should have regular scheduling to update its blob stores’ records.

## Non-Functional Requirements
 Scalability: The system should inherently be distributed and multithreaded, because it has to fetch hundreds of millions of web documents.

  Extensibility: Currently, our design supports HTTP(S) communication protocol and text files storage facilities. For augmented functionality, it   
  should also be extensible for different network communication protocols, able to add multiple modules to process, and store various file formats.

  Consistency: Since our system involves multiple crawling workers, having data consistency among all of them is necessary.

  In the general context, data consistency means the reliability and accuracy of data across a system or dataset. In the web crawler’s context, it 
  refers to the adherence of all the workers to a specific set of rules in their attempt to generate consistent crawled data.

  Performance: The system should be smart enough to limit its crawling to a domain, either by time spent or by the count of the visited URLs of that 
  domain. This process is called self-throttling. The URLs crawled per second and the throughput of the content crawled should be optimal.

  Improved user interface—customized scheduling: Besides the default recrawling, which is a functional requirement, the system should also support 
  the functionality to perform non-routine customized crawling on the system administrator’s demands.

  # Resource Estimation

  We need to estimate various resource requirements for our design.

  Assumptions

  These are the assumptions we’ll use when estimating our resource requirements:

  There are a total of 5 billion web pages.
  The text content per webpage is 2070 KB.
  The metadata for one web page is 500 Bytes.

  ## Storage Estimation
  The collective storage required to store the textual content of 5 billion web pages 
  Total storage per crawl=5 Billion×(2070 KB+500B)=10.35PB
  ![image](https://github.com/shreyatpandey/Coding-Challenges/assets/32083899/19ea7af0-8f4f-49c4-8500-06de00da0348)

  ## Traversal time
  Since the traversal time is just as important as the storage requirements, let’s calculate the approximate time for one-time crawling. Assuming   
  that the average HTTP traversal per webpage is 60 ms, the time to traverse all 5 billion pages will be:
  Total traversal time=5 Billion×60 ms=0.3 Billion seconds= 9.5 

  It’ll take approximately 9.5 years to traverse the whole Internet while using one instance of crawling, but we want to achieve our goal in one day. We can accomplish this by designing our system to support multi-worker architecture and divide the tasks among multiple workers running on different servers.![image](https://github.com/shreyatpandey/Coding-Challenges/assets/32083899/5e7fd49c-4a67-4975-be52-221045801ae2)


  ## Number of servers estimation for multi-worker architecture
  Let’s calculate the number of servers required to finish crawling in one day. Assume that there is only one worker per server.
  No. of days required by 1 server to complete the task=9.5 years×365 days≈3468 days
  One server takes 3,468 days to complete the task.
  How many servers would we need to complete this same task in one day?
  We would need 3,468 servers to complete the same task in just one day.
![image](https://github.com/shreyatpandey/Coding-Challenges/assets/32083899/ecc5fe91-9482-4fcd-82bf-77f9e8d3bbfc)



  



  

