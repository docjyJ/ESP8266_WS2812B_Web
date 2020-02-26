new Vue({
    el: "section.main",
    data: {
        animationList: [
            { id: 1, identifier: "rainbow", title: 'Rainbow', description:"", form : [
                    {type : "percent", name:"name"}
                ]},
            { id: 2, identifier: "pong", title: 'Pong', description:"", form :[
                    {type : "percent", name:"name"},
                    {type : "percent", name:"name2"}
                ]}
        ],
        'scenario': [
            { id: 1, file: "sunrise", title: "Sunrise", description: "Simulate the sunrise"},
            { id: 2, file: "sunset", title: "Sunset", description: "Simulate the sunset"},
            { id: 3, file: "moon", title: "Night Mode", description: "Reduces brightness to work in the dark"},
            { id: 4, file: "movie", title: "Movie Mode", description: "Adapt lighting to watch movies"}
        ]
    }
});

// Materialize
M.AutoInit();
M.Tabs.init(document.querySelector('.tabs'), { swipeable: true });
function openPopup(id) {
    // Initialise popup
    var instances = M.Modal.init(document.getElementById("animation-" + id));
    // Initialise form
    document.getElementById("form-animation-" + id).addEventListener("submit", function (e){
        e.preventDefault();
        formData = new FormData(e.target);
        console.log(formData);
    });

    // Open
    instances.open();
}

// HSV Color Palette
let colorHue = new iro.ColorPicker('#picker', {
    layout : [
        {
            component: iro.ui.Wheel,
            options: {}
        },
    ]
});

let colorSaturation = new iro.ColorPicker('#picker', {
    layout: [
        {
            component: iro.ui.Slider,
            options: {
                sliderType: 'saturation' // can also be 'saturation', 'value', 'alpha' or 'kelvin'
            }
        },
    ]
});

let colorValue = new iro.ColorPicker('#picker', {
    layout: [
        {
            component: iro.ui.Slider,
            options: {
                sliderType: 'value' // can also be 'saturation', 'value', 'alpha' or 'kelvin'
            }
        },
    ]
});

let colorTemp = new iro.ColorPicker('#picker', {
    layout: [
        {
            component: iro.ui.Slider,
            options: {
                sliderType: 'kelvin' // can also be 'saturation', 'value', 'alpha' or 'kelvin'
            }
        },
    ]
});

colorHue.on('color:change', function(color) {
    console.log('Hue:', color.hexString);
});

colorSaturation.on('color:change', function(color) {
    console.log('Sat:', color.hexString);
});


colorValue.on('color:change', function(color) {
    console.log('Value:', color.hexString);
});
