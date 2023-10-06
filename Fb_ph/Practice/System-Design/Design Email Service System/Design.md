# Requirements
 ## Functional Requirements
   * Send and receive emails
   * Fetch all emails
   * Filter emails by read and unread status
   * Search email by subjects,sender and body
   * Anti-spam and anti-virus
## Non Functional Requirments
 * Availability
 * Consistency
 * Scalability

# Numbers:-
 * Number of users:- 1 billion

# Estimation and Constraints
 ## Storage Estimation:-
  * Avg size of email metadata:- 100 kb
  * Emails per day :- 100 emails/day
  * Storage for 1 year:- 1x10^9 x 100 emails/day x 365 x 100 Kb ~ 36.5 PB

 ## Server Estimation:-
  * QPS = 10^9x10 / 10^5 = 10 k QPS

# API Design
 * Endpoint: POST /v1/message
   Send a message to the recipients in the To,Cc, and Bcc headers

  * Endpoint: GET /v1/folders
    Response:-
    {<br>
     id : URI <br>
     name : Name of the folder <br>
     user_id: Reference to the account owner <br>
     }<br>

  * Endpoint: GET /v1/folders/{:folder_id}/messages
  * Endpoint: GET /v1/messages/{:message_id}
    
