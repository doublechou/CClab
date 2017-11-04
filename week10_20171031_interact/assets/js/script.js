var list = document.getElementById('list');
var beijing={lat:39.9042, lng:116.4074};
var paris={lat:48.8566, lng:2.3522};
var uluru = {lat: -25.363, lng: 131.044};
var zoom = 10;
var zoomInit=2;
$(document).ready(function(){


function initmap(zoom,center,){
     var map  = new google.maps.Map(document.getElementById('map'), {
          zoom: zoom,
          center: center
        });


}

function initMap(zoom, center, marker1, marker2, marker3) {
       
        var map  = new google.maps.Map(document.getElementById('map'), {
          zoom: zoom,
          center: center
        });
        var markerParis = new google.maps.Marker({
          position: marker1,
          map: map
        });

        var markerUluru = new google.maps.Marker({
          position: marker2,
          map: map
        });

        var markerBeijing = new google.maps.Marker({
          position: marker3,
          map: map
        });

      }

      function init() {
  //runs first
  initmap(zoomInit, beijing);
}

function app() {
  //thing 2
  //thing 3
}

init();
app();

$('#searchCity').click(function(){
  var baseURL = "https://api.openaq.org/v1/cities";
  $.get(baseURL, function(data,status) {

    if (status == "success") {
      console.log(data);
      //figure out stuff from the data
      initMap(zoomInit, beijing, paris, uluru, beijing);
    }
  });

});



$('#zoom_up').click(function(){
 
      initMap(zoom, beijing, paris, uluru, beijing);
      zoom+=4;
 
});








});

