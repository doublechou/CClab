
var list = document.getElementById('list');
var A = document.getElementById('A');

var i = 0;
var j = 0;
console.log(A);
console.log(list);
A.addEventListener("click", refreshMap);

// runs whole function as soon as page opens. We wrap all our code in this function.
(function() {
  //Set Event listener on Button. When clicked, run the makeRequest function defined below
  document.getElementById('findCity').addEventListener("click", makeRequest);
  document.getElementById('findCity').addEventListener("click", refreshMap);
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
    console.log("5 cities is as below:");
    

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
      } else {
        alert("There was a problem with the request.");
      }
    }
  }
  //Make sure you ad the () after the end of the function.
})();


function initMap() {
        var paris={lat:48.8566, lng:2.3522};
        var uluru = {lat: -25.363, lng: 131.044};

      
        var map  = new google.maps.Map(document.getElementById('map'), {
          zoom: 4,
          center: paris
        });
        var markerParis = new google.maps.Marker({
          position: paris,
          map: map
        });

        var markerUluru = new google.maps.Marker({
          position: uluru,
          map: map
        });


        if (find) {
          console.log("oooooooo");
        }
      }





function refreshMap(){
  var beijing={lat:39.9042, lng:116.4074};
  var map = new google.map.Map(document.getElementById('map'),{
    zoom:4,
    center:beijing
  });
  var markerBeijing = new google.maps.Marker({
    position: beijing,
    map:map
  });

  console.log("@@@@@@");
}
