# RARCH Procedure Fundamentals
 * RACH stands for Random Access Channel. This is the first message from UE to eNB when you power it on.<br>
 
  ## Purpose of RARCH
   * Achieve UP link synchronization between UE and eNB <br>
   * Obtain messages like RRC Connection Request <br>

  ## Criteria for Uplink Syncronization
  * The synchronization process should happen only when there is immediate necessity. <br>
  * The synchronization should be dedicated to only a specific UE. <br>

  ## When RACH Occurs
  * Initial access from RRC_IDLE. <br>
  * RRC Connection Re-establishment procedure. <br>
  * Handover (Contention Based or Non Contetion Based). <br>
  * DL data arrival during RRC_CONNECTED requiring random access procedure. E.g. when UL synchronisation status is “non-synchronised”. <br>
  * UL data arrival during RRC_CONNECTED requiring random access procedure. E.g. when UL synchronisation status is "non-synchronised" or there are no  
    PUCCH resources for SR available.<br>
  * For positioning purpose during RRC_CONNECTED requiring random access procedure. E.g. when timing advance is needed for UE positioning.<br>

  ## What is Preamble?
  * It's nothing but RACH signal.<br>


 

# LTE RACH Procedure Call Flow
  * ![RARCH-Message](https://user-images.githubusercontent.com/32083899/235808555-e4fcb128-ef44-4853-b89f-fc6f037b9a0a.png)







  
 * ![Screenshot 2023-05-11 at 11 58 25 AM](https://github.com/shreyatpandey/Coding-Challenges/assets/32083899/e742ada1-9d52-47c0-917d-c693807fa8cb)













