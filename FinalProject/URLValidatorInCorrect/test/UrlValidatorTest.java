

import junit.framework.TestCase;

//You can use this as a skeleton for your 3 different test approach
//It is an optional to use this file, you can generate your own test file(s) to test the target function!
// Again, it is up to you to use this file or not!





public class UrlValidatorTest extends TestCase {


   public UrlValidatorTest(String testName) {
      super(testName);
   }

   public void testManualEmptyString()
   {   
	   UrlValidator url = new UrlValidator();
	   boolean validUrl = url.isValid("");
	   System.out.println(validUrl);
	   assertFalse(validUrl);
   }
   
   public void testManualNullUrl()
   {   
	   UrlValidator url = new UrlValidator();
	   boolean validUrl = url.isValid(null);
	   System.out.println(validUrl);
	   assertFalse(validUrl);
   }
   
   public void testManualValidUrl1()
   {   
	   UrlValidator url = new UrlValidator();
	   boolean validUrl = url.isValid("ftp://www.google.com");
	   System.out.println(validUrl);
	   assertTrue(validUrl);
   }
   
   public void testManualValidUrl2()
   {   
	   UrlValidator url = new UrlValidator();
	   boolean validUrl = url.isValid("http://www.google.com");
	   System.out.println(validUrl);
	   assertTrue(validUrl);
   }
   
   public void testManualValidUrl3()
   {   
	   UrlValidator url = new UrlValidator();
	   boolean validUrl = url.isValid("https://www.google.com/search");
	   System.out.println(validUrl);
	   assertTrue(validUrl);
   }
   
   public void testManualInValidUrl1()
   {   
	   UrlValidator url = new UrlValidator();
	   boolean validUrl = url.isValid("http/www.123.co//invalid");
	   System.out.println(validUrl);
	   assertFalse(validUrl);
   }
   
   public void testManualInValidUrl2()
   {   
	   UrlValidator url = new UrlValidator();
	   boolean validUrl = url.isValid("www.google.com");
	   System.out.println(validUrl);
	   assertFalse(validUrl);
   }
   
   public void testManualInValidUrl3()
   {   
	   UrlValidator url = new UrlValidator();
	   boolean validUrl = url.isValid("https::www..google.com/??321");
	   System.out.println(validUrl);
	   assertFalse(validUrl);
   }
   
   public void testYourFirstPartition()
   {
	 //You can use this function to implement your First Partition testing	   

   }
   
   public void testYourSecondPartition(){
		 //You can use this function to implement your Second Partition testing	   

   }
   //You need to create more test cases for your Partitions if you need to 
   
   public void testIsValidScheme()
   {
	   //You can use this function for programming based testing
	   String fullUrl;
	   boolean validUrl;
	   
	   UrlValidator url = new UrlValidator();
	   String baseUrl = "://google.com/";
	   ResultPair[] testSchemes = {new ResultPair("http", true),
			   						new ResultPair("https", true),
			   						new ResultPair("ftp", true),
			   						new ResultPair("sms", false),
			   						new ResultPair("", false),
			   						new ResultPair(null, false)};
	   
	   for(int i = 0; i < testSchemes.length; i++) {
		   fullUrl = testSchemes[i].item + baseUrl;
		   validUrl = url.isValid(fullUrl);
		   System.out.println(fullUrl);
		   System.out.println(validUrl);
		   assertEquals(fullUrl, testSchemes[i].valid, validUrl);
	   }  
   }
   


}
