Designing a Web Crawler 
Let's design a Web Crawler that will systematically browse and download the World Wide Web. Web crawlers are also known as web spiders, robots, worms, walkers, and bots. Difficulty Level: Hard 
1. What is a Web Crawler? 
A web crawler is a software program which browses the World Wide Web in a methodical and automated manner. It collects documents by recursively fetching links from a set of starting pages. Many sites, particularly search engines, use web crawling as a means of providing up-to-date data. Search engines download all the pages to create an index on them to perform faster searches. 
Some other uses of web crawlers are: 
•	To test web pages and links for valid syntax and structure. 
•	To monitor sites to see when their structure or contents change. 
•	To maintain mirror sites for popular Web sites. 
•	To search for copyright infringements. 
•	To build a special-purpose index, e.g., one that has some understanding of the content stored in 
multimedia files on the Web. 
2. Requirements and Goals of the System 
Let’s assume we need to crawl all the web. 
Scalability: Our service needs to be scalable such that it can crawl the entire Web and can be used to fetch hundreds of millions of Web documents. 
Extensibility: Our service should be designed in a modular way with the expectation that new functionality will be added to it. There could be newer document types that needs to be downloaded and processed in the future. 
3. Some Design Considerations 
Crawling the web is a complex task, and there are many ways to go about it. We should be asking a few questions before going any further: 
Is it a crawler for HTML pages only? Or should we fetch and store other types of media, such as sound files, images, videos, etc.? This is important because the answer can change the design. If we are writing a general-purpose crawler to download different media types, we might want to break down the parsing module into different sets of modules: one for HTML, another for images, or another for videos, where each module extracts what is considered interesting for that media type. 
Let’s assume for now that our crawler is going to deal with HTML only, but it should be extensible and make it easy to add support for new media types. 
What protocols are we looking at? HTTP? What about FTP links? What different protocols should our crawler handle? For the sake of the exercise, we will assume HTTP. Again, it shouldn’t be hard to extend the design to use FTP and other protocols later. 
What is the expected number of pages we will crawl? How big will the URL database become? 
Let’s assume we need to crawl one billion websites. Since a website can contain many, many URLs, let’s assume an upper bound of 15 billion different web pages that will be reached by our crawler. 
What is ‘RobotsExclusion’ and how should we deal with it? Courteous Web crawlers implement the Robots Exclusion Protocol, which allows Webmasters to declare parts of their sites off limits to crawlers. The Robots Exclusion Protocol requires a Web crawler to fetch a special document called robot.txt which contains these declarations from a Web site before downloading any real content from it. 
4. Capacity Estimation and Constraints 
If we want to crawl 15 billion pages within four weeks, how many pages do we need to fetch per second? 
15B / (4 weeks * 7 days * 86400 sec) ~= 6200 pages/sec 
What about storage? Page sizes vary a lot, but, as mentioned above since, we will be dealing with HTML text only, let’s assume an average page size of 100KB. With each page, if we are storing 500 bytes of metadata, total storage we would need: 
15B * (100KB + 500) ~= 1.5 petabytes 
Assuming a 70% capacity model (we don’t want to go above 70% of the total capacity of our storage system), total storage we will need: 
1.5 petabytes / 0.7 ~= 2.14 petabytes 
5. High Level design 
The basic algorithm executed by any Web crawler is to take a list of seed URLs as its input and repeatedly execute the following steps. 
1. Pick a URL from the unvisited URL list.
2. Determine the IP Address of its host-name.
3. Establish a connection to the host to download the corresponding document. 4. Parse the document contents to look for new URLs.
5. Add the new URLs to the list of unvisited URLs.
6. Process the downloaded document, e.g., store it or index its contents, etc.
7. Go back to step 1 


