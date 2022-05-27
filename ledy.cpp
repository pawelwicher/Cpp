#include <windows.h>

void ClickKey(char vk)
{keybd_event(vk,0,0,0);
keybd_event(vk,0,KEYEVENTF_KEYUP,0);}

void ClickNumLock(void)
{ClickKey((char)VK_NUMLOCK);}

void ClickCapsLock(void)
{ClickKey((char)VK_CAPITAL);}

void ClickScrollLock(void)
{ClickKey((char)VK_SCROLL);}


int main(void)
{
   while (true)
   {
      
      ClickNumLock();      
      ClickScrollLock();
      ClickCapsLock();
      Sleep(150);

      
   }
   return 0;
}
