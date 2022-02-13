# Geek collects the balls
## Medium 
<div class="problem-statement">
                <p></p><p><span style="font-size:18px">There are two parallel roads, each containing <strong>N</strong> and <strong>M</strong> buckets, respectively. Each bucket may contain some balls. The balls in first road are given in an array <strong>a</strong> and balls in the second road in an array <strong>b</strong>.&nbsp;The buckets on both roads are kept in such a way that they are sorted according to the number of balls in them. Geek starts from the end&nbsp;of the road which has the bucket with a lower number of balls(i.e. if buckets are sorted in increasing order, then geek will start from the left side of the road).<br>
Geek&nbsp;can change the road only at a point of intersection i.e.&nbsp;a point where&nbsp;buckets have&nbsp;the same number of balls on&nbsp;two roads. Help Geek&nbsp;collect the maximum number of balls.</span></p>

<p>&nbsp;</p>

<p><strong><span style="font-size:18px">Example 1:</span></strong></p>

<pre style="position: relative;"><span style="font-size:18px"><strong>Input:</strong> 
N = 5, M = 5
a[] = {1, 4, 5, 6, 8}
b[] = {2, 3, 4, 6, 9}
<strong>Output:</strong> 29
<strong>Explanation:</strong> The optimal way to get the 
maximum number of balls is to start from 
road 2. Get 2+3. Then switch at intersection 
point 4. Get 4+5+6. Then switch at intersection
point 6. Get 9. Total = 2+3+4+5+6+9 = 29.</span><div class="open_grepper_editor" title="Edit &amp; Save To Grepper"></div></pre>

<p><strong><span style="font-size:18px">Example 2:</span></strong></p>

<pre style="position: relative;"><span style="font-size:18px"><strong>Input:
</strong>N = 3, M = 3
a[] = {1, 2, 3}
b[] = {4, 5, 6}
<strong>Output:&nbsp;</strong>15</span>
<div class="open_grepper_editor" title="Edit &amp; Save To Grepper"></div></pre>

<p>&nbsp;</p>

<p><br>
<span style="font-size:18px"><strong>Your Task:</strong><br>
You do not need to read input or print anything. Your task is to complete the function <strong>maxBalls()</strong> which takes N, M, a[] and b[] as input parameters and returns the maximum number of balls that can be collected.</span></p>

<p>&nbsp;</p>

<p><span style="font-size:18px"><strong>Expected Time Complexity:</strong> O(N+M)<br>
<strong>Expected Auxililary Space:</strong> O(1)</span></p>

<p>&nbsp;</p>

<p><span style="font-size:18px"><strong>Constraints:</strong><br>
1 ≤ N, M ≤ 10<sup>3</sup><br>
1 ≤ a[i], b[i] ≤ 10<sup>6</sup>&nbsp;&nbsp;</span></p>
 <p></p>
            </div>