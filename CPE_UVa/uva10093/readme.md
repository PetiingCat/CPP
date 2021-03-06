# 10093 - An Easy Problem!  
*通常名字叫easy的都沒那麼簡單*  
## 題意：  
給你一個N進位的整數R，並且保證R一定可以用(N-1)除的盡。你的任務是找出最小的N（2 <= N <= 62，R的長度可能到達10000位數）。在本問題中，62進位數字系統的符號為（0..9，A..Z，a..z）。類似的，61進位數字系統的符號為（0..9，A..Z，a..y）。依此類推，2進位數字系統的符號為（0..1）。  
Input:  
每組測試資料一列，每列有一個整數R。可能包含了+、-符號。最前面也可能含有沒有意義的空白或0。請參考Sample Input。  
Output:  
對每一組測試資料，輸出最小的N（以十進位來表示）。如果找不到，請輸出"such number is impossible!"  
## 解題策略：  
很明顯不是任意數都會符合這個規則，直觀上應該要順著題意不斷將R對N-1取餘數，而N-1可以從R的每個位數中出現的最大數值開始試(例如：999不可能試9進位，一定是10以上的進位)，然而**測資裡出現幾個問題：**
- 題目給的R沒有限制特定進位制、題目給的位數會超過10位數，因此我們無法直接用integer儲存，只能以字串來儲存
- R的位數可能很大、進位制又可能高達62進制，位數不用多長，6、7位數就超過int甚至long long的範圍，**無法直接儲存R**  
- 直接計算R的位數總和，即指數等級求和，花費的**時間非常龐大**
因此網路上給出的解法叫做**同餘計算**  
同餘在離散數學有介紹到，此處補上同餘算法及參考作法來源：https://youtu.be/D3HWEUCdiHg、http://blog.sciencenet.cn/blog-310206-825640.html、https://zh.wikipedia.org/wiki/%E5%90%8C%E9%A4%98#.E4.BF.9D.E6.8C.81.E5.9F.BA.E6.9C.AC.E8.BF.90.E7.AE.97    
## 同餘
以十進位制為例，R = "a1a2a3……an"  
-   依照題意令R為：a1\*999…9(n-1個9) + a2\*999…9(n-2個9) + …… + an-1\*9 ≡ 0 (mod 9)  \_\_\_\_(1) *每個位數都乘上一串9，必定能被9整除*  
-   令一個新的同餘式：a1 + a2 + a3 + …… + an ≡ 0 (mod 9)  \_\_\_\_(2) *令每個位數直接相加也可被9整除，配此式是為了下一步作同餘計算*  
-   根據同餘定理：(1) + (2)之後，左式相加≡右式相加(mod 9)  
    即a1\*10^n-1 + a2\*10^n-2 + …… + an = a1a2a3……an ≡ 0 (mod 9)  
-   得出：若R可被(N-1)整除，則R的**每個位數直接相加**必然可以被(N-1)整除  
如此一來，計算的空間/時間複雜度都大大降低了，感謝偉大的離散數學學者  
## Algorithm:  
1.  任給一個數R，其位數出現的最大數字為M，我們便能猜測R至少是M+1位數，其中(1<= M <=61, M = N-1)  
2.  if(M<=62)  
3.      if("R的位數總和"可以被M整除) then R為M+1位數, terminate(結束)    
4.      else if("R的位數總和"無法被M整除) then M=M+1, 回到步驟2. (用意是猜看看R會不會是更大的位數所構成)  
5.      endif  
6.  else output "such number is impossible!"  
7.  endif  
  