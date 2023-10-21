# Functional Requirement
  * Users can subscribe to watching for a price drop to below a certain "price threshold"
  * users will receive email notification when the price drop occurs
  * price history
  * adaptive price change

# Non Functional Requirement
 * Availability:- Minimum Downtime of the syste,
 * Consistent:- Users should view the same price, that is they are consistent
 * Scalability:- It should scale to support million of users
 * Performance:- Should be fault tolerant to any failure

 # API Design / Schema
 
 **getProductPrice(product_id)**<br>
  Response<br>
  {<br>
   product_id: 5347<br>
   last_price: $xxx<br>
   timestamp:- uuid like 19000890<br>
   }<br>

 **pricewatchdb**<br>
  {<br>
   product_id:uuid<br>
   user_id:23455<br>
   price_threshold:$yyy<br>
   }<br>
 
 **queryw/product_id, price_threshold**

 # High Level Design
  * Database Base:-<br>
    Product Price DB<br>
     1. Write new price<br>
    Price Watch DB<br>
  * URL Frontier- <br>
  * Stale Price Scanner:- <br>
   1. Cron Job which will run every 5 minutes or so.<br>
   2. It look for **oldest timestamp**.<br>
 * Price Watch Backend:- <br>
  This would be connected to the browser-user subscribing to price alerts.<br>
 * Browser-User Subscribing To Price Alerts.<br>
 * Change Database Capture w/ DB trigger. <br>
    1. Connect it with something price drop notifiers.<br>
    2. Cache.<br>
    3. Update this every hour/one a day. Should not get overwhelmed by updating every second or minute.<br>
 * Message broker<br>
    1. Price Drop notifier connected to message broker.<br>
 * Should we use consisten hashing (for key range) or cassandra? <br>
    1. Is it write-heavy? <br>
 * partitioning_key on:- **product_id**<br>
 * sort key:- **user_id**<br>
   1. Why use user_id as sort key? Multiple user_id for each product_id, you cannot have primary key of just product_id.
 **You don't do consisten hashing if the read volume is really,really low, you can get away with this**
* so how are you storing in the price watch DB would it update the existing price or would it add a new entry?<br>
  1. If you are adding a new item, we can use **LSM**, if you we are updating the price, the search should be fast.<br>
  2. Add a new entry every time a new product comes in.

  

