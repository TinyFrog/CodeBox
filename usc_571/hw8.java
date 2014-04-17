import java.io.*;
import java.text.*;
import java.util.*;
import javax.servlet.*;
import javax.servlet.http.*;
import java.net.URLConnection;
import java.net.URL;
import java.net.URLEncoder;
import org.jdom.Document;
import org.jdom.Element;
import org.jdom.JDOMException;
import org.jdom.input.SAXBuilder;
import org.json.*;
import com.metaparadigm.jsonrpc.*;


public class ajax_hotel extends HttpServlet {


    public void doGet(HttpServletRequest request,
                      HttpServletResponse response)
        throws IOException, ServletException
    {

        PrintWriter out = response.getWriter();
     Enumeration e = request.getParameterNames();
     String[] city = request.getParameterValues("city");
     String[] chain = request.getParameterValues("chain");
     String myString = city[0];
     myString = java.net.URLEncoder.encode(myString,"UTF-8");

     String urlString = "http://cs-server.usc.edu:14213/cgi-bin/xml_hw8.pl?city="+myString+"&chain="+chain[0];


     URL url;
     try{
         url = new URL(urlString);
     }catch(java.net.MalformedURLException me){
         out.print("Malformed URL! Make sure the characters you entered are legal");
         return;
     }

     URLConnection urlConnection = url.openConnection();
     urlConnection.setAllowUserInteraction(false);
     InputStream urlStream = url.openStream();
         String line = null;
     /*
        BufferedReader br = new BufferedReader(new InputStreamReader(urlStream));
            while((line=br.readLine())!=null){
               out.println(line);
            }
     */

     try{
     SAXBuilder sb = new SAXBuilder();
     Document document = (Document)sb.build(urlStream);
     Element rootNode = document.getRootElement();
        List list = rootNode.getChildren("hotel");

         JSONObject json = new JSONObject();

          for (int i = 0; i < list.size(); i++) {
             JSONObject hotel = new JSONObject();

             Element node = (Element) list.get(i);

             hotel.put("name",node.getAttributeValue("name"));
             hotel.put("loc",node.getAttributeValue("location"));
             hotel.put("no_of_stars",node.getAttributeValue("no_of_stars"));
             hotel.put("no_of_review",node.getAttributeValue("no_of_reviews"));
             hotel.put("img_url",node.getAttributeValue("img_url"));
             hotel.put("review_url",node.getAttributeValue("review_url"));


              json.accumulate("hotel",hotel);

          }
          JSONObject hotels = new JSONObject();
          hotels.put("hotels",json);
          String output = hotels.toString();
          out.println(output);


          }catch(JDOMException je){

               out.println("Happened!");
               return;
          }

    }

    public void doPost(HttpServletRequest request,
                      HttpServletResponse response)
        throws IOException, ServletException{

     doGet(request,response);
    }

}
