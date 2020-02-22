var sectionAimation = `
        <div class="col s6">
            <div class="card waves-effect waves-block waves-light">
                <div class="card-image">
                    <img v-bind:src="'svg/' + anim.identifier + '.svg'">
                    <a class="btn-floating btn-large halfway-fab waves-effect waves-light red" v-bind:href="'javascript:openPopup(\\\'' + anim.identifier + '\\\')'"><i class="material-icons">add</i></a>
                 </div>
                <div class="card-content">
                    <span class="card-title">{{ anim.title }}</span>
                </div>
            </div>
        </div>
        `;

var popupAimation =`
        <div v-bind:id="'animation-' + anim.identifier" class="modal modal-fixed-footer">
            <div class="modal-content">
                <h4>{{ anim.title }}</h4>
                <p>DESCRIPTION</p>
            </div>
            <div class="modal-footer">
                <a href="#!" class="modal-close waves-effect waves-green btn-flat">Close</a>
            </div>
        </div>
        `;

new Vue({
    el: '#main-preset',
    data: {
        animationList: [
            { id: 1, identifier: "rainbow", title: 'Rainbow'},
            { id: 2, identifier: "pong", title: 'Pong'}
        ]
    },
    components: {
        'section-aimation': {
            props: ['anim'],
            template: sectionAimation
        },
        'popup-aimation': {
            props: ['anim'],
            created : onAnimationCreate(),
            template: popupAimation
        }
    }
});

function openPopup(id) {
    var elems = document.getElementById("animation-" + id);
    var options = {};
    var instances = M.Modal.init(elems, options);
    instances.open();
}

function onAnimationCreate(){
   //
    console.log();
    M.AutoInit();
    /*document.addEventListener('DOMContentLoaded', function() {
        var elems = document.querySelectorAll('.modal');
        var options = {};
        var instances = M.Modal.init(elems);
    });*/
}


/*
<div class="card blue-grey darken-1">
        <div class="card-content white-text">
            <span class="card-title">Card Title</span>
            <p>I am a very simple card. I am good at containing small bits of information.
                I am convenient because I require little markup to use effectively.</p>
        </div>
        <div class="card-action">
            <a href="#">This is a link</a>
            <a href="#">This is a link</a>
        </div>
    </div>







 */