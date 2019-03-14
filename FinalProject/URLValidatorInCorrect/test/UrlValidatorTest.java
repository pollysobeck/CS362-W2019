

import java.util.Random;

import junit.framework.TestCase;

public class UrlValidatorTest extends TestCase {


   public UrlValidatorTest(String testName) {
      super(testName);
   }

   public void testManualEmptyString()
   {   
	   System.out.println("testManualEmptyString");
	   
	   UrlValidator url = new UrlValidator();
	   boolean isValid;
	   System.out.println("Empty string");
	   try {
		   isValid = url.isValid("");
		   assertFalse(isValid);
	   } catch (Exception e) {
		   System.out.println(e);
	   }
	   
	   System.out.println();
   }
   
   public void testManualNullUrl()
   {   
	   System.out.println("testManualNullUrl");
	   
	   UrlValidator url = new UrlValidator();
	   boolean isValid;
	   System.out.println("Null string");
	   try {
		   isValid = url.isValid(null);
		   assertFalse(isValid);
	   } catch (Exception e) {
		   System.out.println(e);
	   }
	   
	   System.out.println();
   }
   
   public void testManualisValid1()
   {   
	   System.out.println("testManualisValid1");
	   
	   String validUrl = "ftp://www.google.com";
	   
	   UrlValidator url = new UrlValidator();
	   boolean isValid;
	   System.out.println(validUrl);
	   try {
		   isValid = url.isValid(validUrl);
		   assertTrue(isValid);
	   } catch (Exception e) {
		   System.out.println(e);
	   }
	   
	   System.out.println();
   }
   
   public void testManualisValid2()
   {   
	   System.out.println("testManualisValid2");
	   
	   String validUrl = "http://www.google.com";
	   
	   UrlValidator url = new UrlValidator();
	   boolean isValid;
	   System.out.println(validUrl);
	   try {
		   isValid = url.isValid(validUrl);
		   assertTrue(isValid);
	   } catch (Exception e) {
		   System.out.println(e);
	   }
	   
	   System.out.println();
   }
   
   public void testManualisValid3()
   {
	   System.out.println("testManualisValid3");
	   
	   String validUrl = "https://www.google.com/search";
	   
	   UrlValidator url = new UrlValidator();
	   boolean isValid;
	   System.out.println(validUrl);
	   try {
		   isValid = url.isValid(validUrl);
		   assertTrue(isValid);
	   } catch (Exception e) {
		   System.out.println(e);
	   }
	   
	   System.out.println();
   }
   
   public void testManualInisValid1()
   {   
	   System.out.println("testManualInisValid1");
	   
	   String badUrl = "http/www.123.co//invalid";
	   
	   UrlValidator url = new UrlValidator();
	   boolean isValid;
	   System.out.println(badUrl);
	   try {
		   isValid = url.isValid(badUrl);
		   assertFalse(isValid);
	   } catch (Exception e) {
		   System.out.println(e);
	   }
	   
	   System.out.println();
   }
   
   public void testManualInisValid2()
   {   
	   System.out.println("testManualInisValid2");
	   
	   String badUrl = "www.google.com";
	   
	   UrlValidator url = new UrlValidator();
	   boolean isValid;
	   System.out.println(badUrl);
	   try {
		   isValid = url.isValid(badUrl);
		   assertFalse(isValid);
	   } catch (Exception e) {
		   System.out.println(e);
	   }
	   
	   System.out.println();
   }
   
   public void testManualInisValid3()
   {   
	   System.out.println("testManualInisValid3");
	   
	   String badUrl = "https::www..google.com/??321";
	   
	   UrlValidator url = new UrlValidator();
	   boolean isValid;
	   System.out.println(badUrl);
	   try {
		   isValid = url.isValid(badUrl);
		   assertFalse(isValid);
	   } catch (Exception e) {
		   System.out.println(e);
	   }
	   
	   System.out.println();
   }
   
   public void testIsValidScheme()
   {
	   //You can use this function for programming based testing
	   System.out.println("testIsValidScheme");
	   
	   String fullUrl;
	   boolean isValid = false;
	   
	   UrlValidator url = new UrlValidator();
	   String baseUrl = "google.com/";
	   
	   for(int i = 0; i < testSchemes.length; i++) {
		   fullUrl = testSchemes[i].item + baseUrl;
		   
		   System.out.println(fullUrl);
		   try {
			   isValid = url.isValid(fullUrl);
			   assertEquals(fullUrl, testSchemes[i].valid, isValid);
		   } catch (Exception e) {
			   System.out.println(e);
		   }  
		   System.out.println();
	   }
   }
   
   public void testRandomUrls()
   {
	   System.out.println("testRandomUrls");
	   ResultPair fullUrl;
	   Boolean isValid;
	   
	   UrlValidator url = new UrlValidator();
	  
	   for(int i = 0; i < 1000; i++) {
		   fullUrl = urlBuilder(); // get randomly built url
		  
		   System.out.println(fullUrl.item);	//print out randomly built url
		   
		   // try executing isValid method
		   try {
			   isValid = url.isValid(fullUrl.item);
			   //System.out.println(fullUrl.valid);	// print out expected result
			   //System.out.println(isValid);		// print out actual result
			   assertEquals(fullUrl.item, (boolean)fullUrl.valid, (boolean)isValid);
		   } catch (Exception e) {
			   System.out.println(e);	//if exception occurs...
		   }  
		   System.out.println();
	   }
   }
   
   private ResultPair urlBuilder() {
	   Random r = new Random();
	   String url;
	   Boolean isValid = true; // start of as isValid = true
	   int index;
	   
	   index = r.nextInt(testSchemes.length);
	   url = testSchemes[index].item;
	   // if url will be invalid, change isValid to false (same for other url parts
	   if (testSchemes[index].valid == false) { isValid = false; }
	   
	   index = r.nextInt(testAuthority.length);
	   url = url + testAuthority[index].item;
	   if (testAuthority[index].valid  == false) { isValid = false; }
	   
	   index = r.nextInt(testPath.length);
	   url = url + testPath[index].item;
	   if (testPath[index].valid  == false) { isValid = false; }
	   
	   index = r.nextInt(testUrlQuery.length);
	   url = url + testUrlQuery[index].item;
	   if (testUrlQuery[index].valid == false) { isValid = false; }
	   
	   ResultPair fullUrl = new ResultPair(url, isValid);
	   
	   return fullUrl;
   }
   
   ResultPair[] testSchemes = {
	   		new ResultPair("http://", true),
			new ResultPair("http:", false),
			new ResultPair("http//", false),
			new ResultPair("https://", true),
			new ResultPair("https:/", false),
			new ResultPair("https", false),
			new ResultPair("ftp://", true),
			new ResultPair("ftp:///", false),
			new ResultPair("sms://", false),
			new ResultPair("://", false),
			new ResultPair("", false)};
   
   ResultPair[] testAuthority = { 
		   	new ResultPair("www.google.com", true),
		  	new ResultPair("test.us", true),
		  	new ResultPair("google.org", true),
		  	new ResultPair("google.", false),
		  	new ResultPair(".google", false),
		   	new ResultPair("www.usa.gov.", true),
		    new ResultPair("test.us", true),
		    new ResultPair("weather.au", true),
		    new ResultPair("0.0.0.0", true),
		    new ResultPair("255.255.255.255", true),
		    new ResultPair("255.org", true),
		    new ResultPair("www.blah.blah", true),
		    new ResultPair("blah.blah", true),
		    new ResultPair("1.2.", false),
		    new ResultPair(".1.2", false),
		    new ResultPair("", false)};
   
   ResultPair[] testPath = {
		    new ResultPair("/testpath", true),
            new ResultPair("/12345", true),
            new ResultPair("/testpath\\", false),  //??
            new ResultPair("/..", false),
            new ResultPair("/../", false),
            new ResultPair("/..//..", false),
            new ResultPair("/testpath/", true),
            new ResultPair("/testpath1/testpath2", true),
            new ResultPair("/testpath1//testpath2", false),
            new ResultPair("", true)};
   
   ResultPair[] testUrlQuery = {
		    new ResultPair("?action=view", true),
           	new ResultPair("?action=edit&mode=up", true),
           	new ResultPair("", true)};
   
}
