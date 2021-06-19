The console app, "Real Capacity Check" is a part of my C++ project "Untrace & Sense Block Storage". Particularly, -

- This app will sense real and healthy (continuous) storage. Looking for size attribute in properties or drive info wont tell you truth always.
- It is a guided console app, will go and check (health & size of) each data block for you.
- Writes random data (not-meaningful) on selected block storage partition as drive letter.
- The data writing process will be continuous till storage gets full and the very own randomly written data is tracked in temp. memory (RAM).
- Process releases the block(s) after writing.
- Verification process initiates the reading of those data blocks, written by app, to check the integrity using that randomly written data tracked in temp. memory.
- When an unhealthy data block (read error or bad block) is encounterd, app reports it on console screen with calculated healthy and continuous part of storage capacity, in the end.
- READ THE WARNING CAREFULLY and as you can also exit at that stage if you disagree the warning.
- NOT REQUIRE INTERNET ACCESS.
- NOT CAPABLE OF READING USER's DATA.

    So, enjoy the verified reliability !
