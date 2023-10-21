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
{ <br>
 product_id: 5347<br>
 last_price: $xxx<br>
 timestamp:- uuid like 19000890<br>
 }

 # High Level Design
  * Database Base:-<br>
    Product Price DB<br>
     1. Write new price<br>
    Price Watch DB<br>
 * URL Frontier- <br>
 * Stale Price Scanner:- <br>
  1. Cron Job which will run every 5 minutes or so.<br> 
