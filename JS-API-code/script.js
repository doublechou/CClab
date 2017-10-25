//Some Global Variables to Hold Info for Later

// //Constructors for API URL Request. We'll use these later
// var baseURL = "https://ghibliapi.herokuapp.com";
// var films = "/films";
// var id1 = "/58611129-2dbc-4a81-a72f-77ddfc1b1b49";
// var fullURL = baseURL + films + id1;

//Pull in our HTML elements so we can talk to them using JS
var list = document.getElementById('list');
var hint = document.getElementById('hint');
var i = 0;
var j = 0;

// runs whole function as soon as page opens. We wrap all our code in this function.
(function() {
  //Set Event listener on Button. When clicked, run the makeRequest function defined below
  document.getElementById("ajaxButton").addEventListener("click", makeRequest);
 
  //variable to hold httpRequest info
  var httpRequest;
  //makeRequest function runs when button is clicked
  function makeRequest() {
    httpRequest = new XMLHttpRequest();
    //If something is wrong with request, pop-up an alert that says so
    if (!httpRequest) {
      alert("It did not work :(");
      return false;
    }
    httpRequest.onreadystatechange = fillInfo;
    httpRequest.open(
      "GET", "https://api.openaq.org/v1/cities"
    );
    httpRequest.send();
  }

  //Function that Runs When API Call is finished
  function fillInfo() {
    //variable to hold the response from API GET request
    var responseContent;
    var listArray = [];

   // document.write("10 cities is as below:");
    console.log("10 cities is as below:");
    

    if (httpRequest.readyState === XMLHttpRequest.DONE) {
      if (httpRequest.status === 200) {
          console.log(httpRequest.responseText);

          console.log("@@@@@");
        
          responseContent = JSON.parse(httpRequest.responseText);

          for (i = j;i<j+5;i++) {

            console.log(responseContent.results[i].city);
    
            var listItem = document.createElement('li');
            listItem.appendChild(document.createTextNode(responseContent.results[i].city));
            list.appendChild(listItem);
          }
          j+=5;

          /*Add results to a list*/
        
//         /*Save the response in responseContent variable.
//         Note that the response has ' ' around it. This means it is a String.*/
//         responseContent = httpRequest.responseText;
//         console.log(responseContent);
//         /*
//         Since responseContent is a string, we need to change it into an object
//         to use it. To do this, we can use JSON.parse. This parses or translates
//         a JSON object from a String.
//         */
//         var parsed = JSON.parse(responseContent);
//         //Now we can use the info the same way as an object.
//         console.log(parsed.title);
//         console.log(parsed.description);
        
//         /* Now lets update our actual HTML using this info.
//         We already have two variables, title and description which we
//         pulled into our code using document.getElementById() earlier.
//         We can update these variables with the information from the API
//         by using the .innerHTML command. */
//         title.innerHTML = parsed.title;
//         description.innerHTML = parsed.description;            
      } else {
        alert("There was a problem with the request.");
      }
    }
  }
  //Make sure you ad the () after the end of the function.
})();