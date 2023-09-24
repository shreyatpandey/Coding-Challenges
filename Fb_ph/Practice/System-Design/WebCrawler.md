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
  
  It’ll take approximately 9.5 years to traverse the whole Internet while using one instance of crawling, but we want to achieve our goal in one day. We can accomplish this by designing our system to support multi-worker architecture and divide the tasks among multiple workers running on different servers.

  
  ![image](https://github.com/shreyatpandey/Coding-Challenges/assets/32083899/ecc5fe91-9482-4fcd-82bf-77f9e8d3bbfc)

  
  ![image](https://github.com/shreyatpandey/Coding-Challenges/assets/32083899/2d635d24-85bd-4df6-bc80-b83ac4b4f606)

  
  # Design of Web Crawler
  
  ![image](https://github.com/shreyatpandey/Coding-Challenges/assets/32083899/8284a487-a7f2-4385-bd5a-ebfaff93c56f)


  ![image](https://github.com/shreyatpandey/Coding-Challenges/assets/32083899/bc6ac649-a5ac-4f71-aa56-aa399e33fe64)


  ![image](https://github.com/shreyatpandey/Coding-Challenges/assets/32083899/955ee756-9a6a-4f28-97cf-71196cbdf10f)


  ![image](https://github.com/shreyatpandey/Coding-Challenges/assets/32083899/cd25cfaa-d9fc-43d5-bf51-b4fd48ac89a2)


  ![image](https://github.com/shreyatpandey/Coding-Challenges/assets/32083899/9628242b-fc8a-4d13-867d-b565b3cd8905)

  
  ![image](https://github.com/shreyatpandey/Coding-Challenges/assets/32083899/a3da034b-e3b3-4ace-9095-255821b88737)

  # Design Improvements

  ![image](https://github.com/shreyatpandey/Coding-Challenges/assets/32083899/6454a90e-b1d5-45cf-b773-bc6e4a63ee31)

 
  ![image](https://github.com/shreyatpandey/Coding-Challenges/assets/32083899/766bb8a3-e353-4db7-a9ed-c51f44279bec)

  
  ![image](https://github.com/shreyatpandey/Coding-Challenges/assets/32083899/288c3cee-f205-4ff9-9ec8-b138496bce63)


  ![image](https://github.com/shreyatpandey/Coding-Challenges/assets/32083899/b3a68105-4e41-4099-a218-2999fae329c3)


  ![image](https://github.com/shreyatpandey/Coding-Challenges/assets/32083899/eda1e73a-2e9b-4d9e-bb03-6fac2607d87b)










  



  

