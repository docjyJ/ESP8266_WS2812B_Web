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
        ]
    }
});

function openPopup(id) {
    M.AutoInit();
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
