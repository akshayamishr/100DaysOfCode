package com.example.appoftheday2.view

import android.os.Bundle
import androidx.fragment.app.Fragment
import android.view.LayoutInflater
import android.view.View
import android.view.ViewGroup
import android.widget.Toast
import androidx.fragment.app.activityViewModels
import androidx.navigation.fragment.findNavController
import com.bumptech.glide.Glide
import com.example.appoftheday2.R
import com.example.appoftheday2.databinding.FragmentSecondBinding
import com.example.appoftheday2.viewModel.ImageSet
import com.google.fragmentstest.viewmodel.CountViewModel

/**
 * A simple [Fragment] subclass as the second destination in the navigation.
 */
class SecondFragment : Fragment() {

    private var _binding: FragmentSecondBinding? = null
    private val viewModel: CountViewModel by activityViewModels()
    private val imageSetViewModel : ImageSet by activityViewModels()
    // This property is only valid between onCreateView and
    // onDestroyView.
    private val binding get() = _binding!!

    override fun onCreateView(
        inflater: LayoutInflater, container: ViewGroup?,
        savedInstanceState: Bundle?
    ): View? {

        _binding = FragmentSecondBinding.inflate(inflater, container, false)
        return binding.root

    }

    override fun onViewCreated(view: View, savedInstanceState: Bundle?) {
        super.onViewCreated(view, savedInstanceState)

        val count = arguments?.getInt("key", 0)

        binding.PreviousScreenButton.setOnClickListener() {
            findNavController().navigate(R.id.action_SecondFragment_to_FirstFragment)
            Toast.makeText(requireContext(), "Fragment changed successfully", Toast.LENGTH_SHORT).show()
        }

        // lifecycleowner -> provides a way to unsubscribe when we the app / page / fragment is not used
        viewModel.getCount().observe(viewLifecycleOwner) {
            binding.countView.text= it.toString()
        }
        val imageUrl = imageSetViewModel.getImage(viewModel.getCount().value!!)
        imageUrl?.let {
            // Use the Glide library to load the image into the ImageView
            Glide
                .with(this) // Replace with your actual fragment reference
                .load(imageUrl)
                .into(binding.DownloadedImage)
        }
//        binding.btnDecrement.setOnClickListener {
//            viewModel.decrement()
//        }
    }

    override fun onDestroyView() {
        super.onDestroyView()
        _binding = null
    }
}