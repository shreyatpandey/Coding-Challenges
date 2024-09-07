# Functional Requirement
1. Ad click auction + impression placement<br>
2. Ad click aggregation<br>
  a. This from ad click counter.<br>

# Non-Functional Requirement
1. High Available system<br>
  a. Use closer geographically distributed server.<br>
2. Scalability<br>
3. Low Latency<br>
 a. Used CDN's <br>

# Numbers and Estimation
1. Read Heavy<br>
2. 10M+ TPS of reads<br>
3. 100k+ TPS of reads<br>

# Approaches
 1. Impression serving / "placement" ID <br>
   a. "impression ID" <br>
   b. Ad ID + de-dupe key <br>
 2. One big ML Model Vs. model for each ad from the "Model Store"<br>
   a. Model(Ad Features, User Features) -> click probability<br>
   b. Ad ID -> Model(User Feature) -> click probability

# Data Schema
1. {<br>
    impression ID: <br>
    timestamp:9087888<br>
    }<br>
2. click_Table<br>
   { <br>
     user_id:<br>
     ad_id: <br>
     de_dupe:<br>
     timestampe:78900<br>
   }<br>

# High Level Design
1. Browser-User Loading Ad<br>
 a. User ID<br>
 b. AD ID/"Impression"<br>
  a. Just view an ad<br>
  b. Just have it on the page, user just want to view and not click on it.<br>

2. Browser-User Fetching Ad Content.<br>
  a. Ad ID<br>
  b. Picture of ad say like energy drink, monster from Ad Metadata store.<br>
  c. Return distributed storage URL like Azure Blob Storage, S3.<br>
  d. Copy CDN.<br>
  e. You can get thousands of impression/day
  f. cost per click (CPC) , cost per impression (CPM) - $2.00

4. Browser-User Scrolling Page<br>
 a. impression ID, viewability metric.<br>
 b. Response as 200 Ok.<br>

5. Browser-User Clicks Ad.<br>
 1. record impression Id, viewability metric.<br>
 2. Mayget 300x redirect.<br>
 3. Go for redirect lookup.<br> just like tiny URL

6. Distributed message pipeline/Kafka.<br>
  1. Data Warehouse(impression)<br>
  2. Data Warehouse(viewability)<br>
  3. Data Warehouse(clicks)<br>

7. Sequencer.<br>
  1. Sequencer/UUID.<br>
     a. Attached with Auction & Placement Service.<br>
     b. Data Model(/s).<br>

will adding secondary indexes (local or global) work? (PS :- I just added this point out of curiosity to know more if that would really work) ---- data warehouses tend to not have secondary indices because you tend to do full table scans<b>
     


