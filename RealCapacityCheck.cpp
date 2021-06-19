#include <iostream> // for cin cout
#include <fstream>  // for file operations
#include <string>  // for string operations
#include <iomanip>  // for clock_t, clock()
using namespace std;

int main()
{    //      START CODE BELOW !
    clock_t s;
    short fId=0, LfId=0, rErr=0;
    long long rVef=0;
    char dLett=0;
    fstream TheFile;
    const char wDat[3039]="100100100101101101101001001001011011011010101010 100100100101101101101001001001011011011010101010 100100100101101101101001001001011011011010101010 100100100101101101101001001001011011011010101010 100100100101101101101001001001011011011010101010 100100100101101101101001001001011011011010101010 100100100101101101101001001001011011011010101010 100100100101101101101001001001011011011010101010 100100100101101101101001001001011011011010101010 100100100101101101101001001001011011011010101010 100100100101101101101001001001011011011010101010 100100100101101101101001001001011011011010101010 100100100101101101101001001001011011011010101010 100100100101101101101001001001011011011010101010 100100100101101101101001001001011011011010101010 100100100101101101101001001001011011011010101010 100100100101101101101001001001011011011010101010 100100100101101101101001001001011011011010101010 100100100101101101101001001001011011011010101010 100100100101101101101001001001011011011010101010 100100100101101101101001001001011011011010101010 100100100101101101101001001001011011011010101010 100100100101101101101001001001011011011010101010 100100100101101101101001001001011011011010101010 100100100101101101101001001001011011011010101010 100100100101101101101001001001011011011010101010 100100100101101101101001001001011011011010101010 100100100101101101101001001001011011011010101010 100100100101101101101001001001011011011010101010 100100100101101101101001001001011011011010101010 100100100101101101101001001001011011011010101010 100100100101101101101001001001011011011010101010 100100100101101101101001001001011011011010101010 100100100101101101101001001001011011011010101010 100100100101101101101001001001011011011010101010 100100100101101101101001001001011011011010101010 100100100101101101101001001001011011011010101010 100100100101101101101001001001011011011010101010 100100100101101101101001001001011011011010101010 100100100101101101101001001001011011011010101010 100100100101101101101001001001011011011010101010 100100100101101101101001001001011011011010101010 100100100101101101101001001001011011011010101010 100100100101101101101001001001011011011010101010 100100100101101101101001001001011011011010101010 100100100101101101101001001001011011011010101010 100100100101101101101001001001011011011010101010 100100100101101101101001001001011011011010101010 100100100101101101101001001001011011011010101010 100100100101101101101001001001011011011010101010 100100100101101101101001001001011011011010101010 100100100101101101101001001001011011011010101010 100100100101101101101001001001011011011010101010 100100100101101101101001001001011011011010101010 100100100101101101101001001001011011011010101010 100100100101101101101001001001011011011010101010 100100100101101101101001001001011011011010101010 100100100101101101101001001001011011011010101010 100100100101101101101001001001011011011010101010 100100100101101101101001001001011011011010101010 100100100101101101101001001001011011011010101010 100100100101101101101001001001011011011010101010x";
    string cDat="", rDat="";

    // Select Drive.
    AskDrive:
    cout<<"\n Provide the correct target drive letter (like d or D)-  ";
    cin>>dLett;
    if (!(dLett>='a' && dLett<='z') && !(dLett>='A' && dLett<='Z'))
    {
        cout<<"\n Invalid letter, please try again.";
        goto AskDrive;
    }
    // Checking the drive's existence.
    cout<<"\n ";
    if (short (system((string()+dLett+':').c_str()))==1)
        goto AskDrive;

    // Creating dedicated dir.
    system((string()+"mkdir "+dLett+":\\RCCheck").c_str());
    // Creating new file.
    CreateNew:
    TheFile.open(string()+dLett+":/RCCheck/read.BLOCK"+to_string(fId), ios::out);
	if (!TheFile)
    {
        cout<<" Block file not created, following maybe the reason(s)-\n\
             - Access denied or you are not an admin.\n\
             - Drive has no more available space.\n\n\
        Please check one/all and then, ";
        system("pause");
        goto CreateNew;
    }
    // init Warning
    if (fId==0)
    {
        cout<<" ONLY YOUR NON-DELETED DATA IS 100% SAFE.\n\n The available space on selected block storage will be checked for real and healthy capacity.\n\n\tClose the console  OR  ";
        system("pause");
        s=clock();  // Current clock time stored in "s" for START
    }

    // Start writing new data.
    cout<<"\n Writing block #"<<fId;
    while (TheFile.tellg()<=524288000 && TheFile.tellg()!=-1)  // 2000MB (2097152000) Max file size (1char == 1byte).
        // 3038 bytes data.
        TheFile <<wDat;

    // If storage got full.
    if (TheFile.tellg()==-1)    // OR Testing condition fId>10.
    {
        TheFile.close();
        goto VerifyIt;
    }
    // Else, create next (another) file.
    TheFile.close();
    fId++;
    goto CreateNew;
    
    // Written data is to be verified.
    VerifyIt:
    // Converting written data to a check data string.
    cDat=(string()+wDat);
    cDat.pop_back();
    // Identify & keep the last file.
    TheFile.open(string()+dLett+":/RCCheck/read.BLOCK"+to_string(fId), ios::in);
    if (!TheFile)
        fId--;
    else
    {
        TheFile.close();
        LfId=fId;
    }
    // Starting from 1st file.
    for (fId=0; fId<=LfId; fId++)
    {
        TheFile.open(string()+dLett+":/RCCheck/read.BLOCK"+to_string(fId), ios::in);
        cout<<"\n Verifying block #"<<fId;
        rErr=0;
        while (!TheFile.eof())
        {
            getline(TheFile, rDat, 'x');
            rErr+=!(rDat==cDat);
            rVef+=(rDat==cDat);
        }
        TheFile.close();
        if (rErr>1)
        {
            cout<<"\n Read Error: Something is wrong with drive's block(s).\n\n Take a note of [Verified capacity] and try again.";
            system((string()+"rmdir /s /q "+dLett+":\\RCCheck").c_str());
            goto TheEnd;
        }
    }        
    // Removing rmdir /s /q a:\RCCheck
    system((string()+"rmdir /s /q "+dLett+":\\RCCheck").c_str());
    cout<<"\n\n All blocks reached! Temporary block files are now cleared.";

    TheEnd:
    //      END CODE ABOVE !
    clock_t e=clock();  // Current clock time stored in "e" for END
    rVef=(rVef*3038)/1024/1024;
    cout<<"\n\n Verified available capacity = "<<rVef<<" MB(s) or "<<(float)rVef/1024<<" GB(s), ";
    system("pause");
    cout<<"\n Time taken = "<<double(e-s) / double(CLOCKS_PER_SEC)<<"s, ";  
    system("pause");
    return 0;
}
