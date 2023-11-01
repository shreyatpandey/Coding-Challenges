# Functional Requirement
1. Ad click auction + impression placement<br>
2. Ad click aggregation<br>

# Approaches
 1. Impression serving / "placement" ID <br>
   a. "impression ID" <br>
   b. Ad ID + de-dupe key <br>
 2. One big ML Model Vs. model for each ad from the "Model Store"<br>
   a. Model(Ad Features, User Features) -> click probability<br>
   b. Ad ID -> Model(User Feature) -> click probability

